//
// Created by chen on 2020/8/23.
//

#ifndef MYMEDIAPLAYER_FFDECODE_H
#define MYMEDIAPLAYER_FFDECODE_H

#include "IDecode.h"
struct AVCodecContext;

class FFDecode : public IDecode{
public:
    bool Open(XParameter param) override;

protected:
    AVCodecContext *codec = nullptr;
};


#endif //MYMEDIAPLAYER_FFDECODE_H
