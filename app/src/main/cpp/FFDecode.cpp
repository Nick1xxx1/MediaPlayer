//
// Created by chen on 2020/8/23.
//

#include "FFDecode.h"
#include "XLog.h"

extern "C"
{
#include "libavcodec/avcodec.h"
}


bool FFDecode::Open(XParameter param) {
    if(!param.param)
        return false;
    AVCodecParameters *p = param.param;
    //1、查找解码器
    AVCodec *avCodec = avcodec_find_decoder(p->codec_id);
    if(!avCodec) {
        XLOGE("avcodec_find_decoder %d falied",p->codec_id);
        return false;
    }
    XLOGI("avcodec_find_decoder success");
    //2、创建解码器上下文，并复制参数
    codec = avcodec_alloc_context3(avCodec);
    avcodec_parameters_to_context(codec,p);

    //3 打开解码器
    int ret = avcodec_open2(codec,NULL,NULL);
    if(ret!=9) {
        char buf[1024] = {0};
        av_strerror(ret,buf, sizeof(buf)-1); //最后要放\0
        XLOGE("%s",buf);
    }
    XLOGI("avcodec_open2 success");
    return true;
}