#include <jni.h>
#include <string>

#include "FFDemux.h"
#include "XData.h"
#include "XLog.h"
#include "IDecode.h"
#include "FFDecode.h"

class TestObs : public IObserver {
public:
    void Update(XData d) {
//        XLOGI("TestObs update data size is %d",d.size);
    }
};

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_mymediaplayer_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";

    /////////////////////////////////
    //测试用代码
    TestObs *testObs = new TestObs();
    IDemux *de = new FFDemux();
    de->addObserver(testObs);
    de->Open("/sdcard/1080.mp4");
    IDecode *vDecode = new FFDecode();
    vDecode->Open(de->getVideoParam());
    de->Start();
    XSleep(3000);
    de->Stop();
    delete testObs;
//    for(;;) {
//        XData d = de->Read();
//        XLOGI("read data size is %d",d.size);
//    }
//    ////////////////////////////////

    return env->NewStringUTF(hello.c_str());
}
