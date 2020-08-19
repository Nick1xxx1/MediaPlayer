//
// Created by chen on 2020/8/17.
//

#ifndef MYMEDIAPLAYER_XDATA_H
#define MYMEDIAPLAYER_XDATA_H


struct XData{
    unsigned char *data = nullptr; //存放读取的packet数据
    int size =0; //数据大小
    void Drop();
};


#endif //MYMEDIAPLAYER_XDATA_H
