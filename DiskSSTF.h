//
// Created by AlexGrandbell on 24-11-27.
//

#ifndef DISKSCHEDULING_DISKSSTF_H
#define DISKSCHEDULING_DISKSSTF_H

#include "Disk.h"

//最短寻道时间优先算法
class DiskSSTF: public Disk {
public:
    DiskSSTF(vector<int> requests, bool direction, int current): Disk(requests, direction, current) {}
    void run() override;
};


#endif //DISKSCHEDULING_DISKSSTF_H
