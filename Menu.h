//
// Created by AlexGrandbell on 24-11-27.
//

#ifndef DISKSCHEDULING_MENU_H
#define DISKSCHEDULING_MENU_H

#include "DiskFCFS.h"
#include "DiskSCAN.h"
#include "DiskSSFT.h"

//菜单类
class Menu {
public:
    Menu():current(0),direction(true),mode(1) {
        requests = {1,2,3};
    }

    void PrintMenu();

private:
    vector<int> requests;
    int current;
    bool direction;
    int mode;//1-FCFS 2-SSFT 3-SCAN

    void setRequests();
    void setCurrent();
    void setDirection();
    void setMode();

    void run();
};


#endif //DISKSCHEDULING_MENU_H
