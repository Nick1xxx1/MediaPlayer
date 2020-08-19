//
// Created by chen on 2020/8/17.
//

#include "IDemux.h"
#include "XData.h"
#include "XLog.h"

void IDemux::Main() {
    while(!isExit) {
        XData d = Read();
        if(d.size>0)
            Notify(d);
//        XLOGI("IDemux read %d",d.size);
    }
}