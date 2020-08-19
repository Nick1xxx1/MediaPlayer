//
// Created by chen on 2020/8/19.
//

#ifndef MYMEDIAPLAYER_XTHREAD_H
#define MYMEDIAPLAYER_XTHREAD_H

//sleep毫秒
void XSleep(int ms);

//使用c++11线程库
class XThread {
public:
    //启动线程
    virtual void Start();
    //通过控制isExit安全停止线程（不一定成功)
    virtual void Stop();
    //入口主函数
    virtual void Main() {};
protected:
    bool isExit;
    bool isRunning;
private:
    void ThreadMain();
};


#endif //MYMEDIAPLAYER_XTHREAD_H
