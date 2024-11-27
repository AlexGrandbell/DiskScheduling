//
// Created by AlexGrandbell on 24-11-27.
//

#ifndef DISKSCHEDULING_DISK_H
#define DISKSCHEDULING_DISK_H

#include <vector>
#include <iostream>

using namespace std;

//磁盘类
class Disk {
public:
    vector<int> requests;//请求序列
    bool direction;//磁头移动方向,true为向外,false为向内
    int current;//当前磁道
    int totalMoveNum;//总移动磁道数

    Disk():direction(true),current(0),totalMoveNum(0) {
        requests = {1,2,3};
    }
    Disk(vector<int> requests, bool direction, int current):requests(requests),direction(direction),current(current),totalMoveNum(0) {}

    virtual void run() = 0;

    void showBaseInfo();
};


#endif //DISKSCHEDULING_DISK_H
