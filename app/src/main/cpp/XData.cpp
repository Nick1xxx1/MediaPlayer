//
// Created by chen on 2020/8/17.
//

extern "C" {
#include <libavcodec/avcodec.h>
}
#include "XData.h"

void XData::Drop() {
    if(!data) return;
    av_packet_free((AVPacket**)&data);
    data = nullptr;
    size = 0;
}