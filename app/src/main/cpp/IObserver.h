//
// Created by chen on 2020/8/19.
//

#ifndef MYMEDIAPLAYER_IOBSERVER_H
#define MYMEDIAPLAYER_IOBSERVER_H

#include "XData.h"
#include "XThread.h"
#include <vector>
#include <mutex>
//观察者和主体
class IObserver : public XThread {
public:
    //观察者接收数据函数
    virtual void Update(XData data) {}

    //主体函数 添加观察者（线程安全）
    void addObserver(IObserver *obs);

    //通知所有观察者（线程安全）
    void Notify(XData data);
protected:
    std::vector<IObserver *> obss;
    std::mutex mux;
};


#endif //MYMEDIAPLAYER_IOBSERVER_H
