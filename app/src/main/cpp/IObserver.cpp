//
// Created by chen on 2020/8/19.
//

#include "IObserver.h"
using namespace std;

void IObserver::addObserver(IObserver *obs) {
    if(!obs)
        return;
    mux.lock();
    obss.push_back(obs);
    mux.unlock();
}

void IObserver::Notify(XData data) {
    mux.lock();
    int theSize = obss.size();
    for(vector<IObserver *>::size_type i =0;i<theSize;++i) {
        obss[i]->Update(data);
    }
    mux.unlock();
}