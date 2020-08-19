//
// Created by chen on 2020/8/19.
//

#include "XThread.h"
#include <thread>
#include "XLog.h"
using namespace std;

void XSleep(int ms) {
    chrono::milliseconds du(ms);
    this_thread::sleep_for(du);
}

void XThread::Start() {
    isExit = false;
    thread th(&XThread::ThreadMain,this);
    th.detach();
}

void XThread::ThreadMain() {
    XLOGI("进入线程函数");
    isRunning = true;
    Main();
    XLOGI("退出线程函数");
    isRunning = false;
}

void XThread::Stop() {
    isExit = true;
    for (int i =0;i<200;i++) {
        if(!isRunning) {
            XLOGI("停止线程成功");
            return;
        }
        XSleep(1);
    }
    XLOGI("停止线程超时");
}