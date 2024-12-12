//
// Created by AlexGrandbell on 24-11-27.
//

#include "DiskFCFS.h"

//先来先服务算法，同时输出每次移动的磁道号
void DiskFCFS::run() {
    cout << "先来先服务算法" << endl;
    showBaseInfo();
    cout << "移动磁道序列: "<<current<< " ";
    for (int i = 0; i < requests.size(); ++i) {
        cout << requests[i] << " ";
        totalMoveNum += abs(requests[i] - current);
        current = requests[i];
    }
    cout << endl;
    cout << "总移动磁道数: " << totalMoveNum << endl;
}