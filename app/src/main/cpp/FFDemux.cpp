//
// Created by chen on 2020/8/17.
//

#include "FFDemux.h"
#include "XData.h"
#include "XLog.h"

#ifdef __cplusplus
extern "C" {
#endif
#include "libavcodec/avcodec.h"
#include "libavformat/avformat.h"
#ifdef __cplusplus
};
#endif

double r2d(AVRational avRational) {
    return (avRational.den==0||avRational.num==0)?0:(double)avRational.den/(double)avRational.num;
}

FFDemux::FFDemux() {
    static bool isFirst = true;
    if(isFirst) {
        //注册所有封装器
        av_register_all();

        //注册所有解码器
        avcodec_register_all();

        //初始化网络
        avformat_network_init();
        XLOGI("register ffmpeg");
        isFirst = false;
    }
}

bool FFDemux::Open(const char *url) {
    XLOGI("Open file %s begin",url);
    int ret = avformat_open_input(&ic,url,0,0);
    if(ret!=0) {
        char buf[1024] = {0};
        av_strerror(ret,buf, sizeof(buf));
        XLOGE("FFDemux open %s failed, the error is:%s",url,buf);
        return false;
    }

    //读取文件信息
    ret = avformat_find_stream_info(ic,0);
    if(ret!=0) {
        char buf[1024] = {0};
        av_strerror(ret,buf, sizeof(buf));
        XLOGE("avformat_find_stream_info failed, the error is:%s",buf);
        return false;
    }

    totalMs = ic->duration/(AV_TIME_BASE/1000);
    XLOGI("total ms = %d",totalMs);

    return true;
}

XData FFDemux::Read() {
    if(!ic)
        return XData();
    XData d;
    AVPacket *avPacket = av_packet_alloc();
    int ret = av_read_frame(ic,avPacket);
    if(ret != 0) {
        av_packet_free(&avPacket);
        return XData();
    }
//    XLOGI("packet size is %d , pts: %lld",avPacket->size,avPacket->pts);
    d.data = (unsigned char*)avPacket;
    d.size = avPacket->size;
    return d;
}