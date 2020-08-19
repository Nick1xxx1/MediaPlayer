//
// Created by chen on 2020/8/17.
//

#ifndef MYMEDIAPLAYER_IDEMUX_H
#define MYMEDIAPLAYER_IDEMUX_H

class XData;
//解封装接口类
class IDemux {
public:
    //打开文件或者流媒体 rtmp http rtsp
    virtual bool Open(const char *url) = 0;

    //读取一帧，数据由调用者清理
    virtual XData Read() = 0;

    //总时长（毫秒）
    int totalMs = 0;
};


#endif //MYMEDIAPLAYER_IDEMUX_H
