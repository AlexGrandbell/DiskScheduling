//
// Created by AlexGrandbell on 24-11-27.
//

#ifndef DISKSCHEDULING_DISKFCFS_H
#define DISKSCHEDULING_DISKFCFS_H

#include "Disk.h"

//先来先服务算法
class DiskFCFS: public Disk {
public:
    DiskFCFS(vector<int> requests, bool direction, int current):Disk(requests, direction, current) {}
    void run() override;
};


#endif //DISKSCHEDULING_DISKFCFS_H
