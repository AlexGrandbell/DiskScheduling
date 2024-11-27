//
// Created by AlexGrandbell on 24-11-27.
//

#ifndef DISKSCHEDULING_DISKSCAN_H
#define DISKSCHEDULING_DISKSCAN_H

#include "Disk.h"

//扫描算法（电梯算法）
class DiskSCAN: public Disk {
public:
    DiskSCAN(vector<int> requests, bool direction, int current):Disk(requests, direction, current) {}
    void run() override;
};


#endif //DISKSCHEDULING_DISKSCAN_H
