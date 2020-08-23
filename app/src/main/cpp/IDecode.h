//
// Created by chen on 2020/8/23.
//

#ifndef MYMEDIAPLAYER_IDECODE_H
#define MYMEDIAPLAYER_IDECODE_H

#include "XParameter.h"
#include "IObserver.h"

//解码接口，支持硬解码
class IDecode : public IObserver {
public:
    //打开解码器
    virtual bool Open(XParameter param) = 0;

};


#endif //MYMEDIAPLAYER_IDECODE_H
