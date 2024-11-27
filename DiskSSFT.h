//
// Created by AlexGrandbell on 24-11-27.
//

#ifndef DISKSCHEDULING_DISKSSFT_H
#define DISKSCHEDULING_DISKSSFT_H

#include "Disk.h"

//最短寻道时间优先算法
class DiskSSFT: public Disk {
public:
    DiskSSFT(vector<int> requests, bool direction, int current):Disk(requests, direction, current) {}
    void run() override;
};


#endif //DISKSCHEDULING_DISKSSFT_H
