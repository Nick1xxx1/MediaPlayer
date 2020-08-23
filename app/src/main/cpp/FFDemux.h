//
// Created by chen on 2020/8/17.
//

#ifndef MYMEDIAPLAYER_FFDEMUX_H
#define MYMEDIAPLAYER_FFDEMUX_H

#include "IDemux.h"

struct AVFormatContext;

class FFDemux : public IDemux{
public:
    FFDemux();
    virtual bool Open(const char *url);
    virtual XData Read();
    virtual XParameter getVideoParam();
private:
    AVFormatContext *ic = nullptr;
};


#endif //MYMEDIAPLAYER_FFDEMUX_H
