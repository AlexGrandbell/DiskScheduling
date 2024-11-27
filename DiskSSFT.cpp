//
// Created by AlexGrandbell on 24-11-27.
//

#include "DiskSSFT.h"

//最短寻道时间优先算法
void DiskSSFT::run() {
    cout << "最短寻道时间优先算法" << endl;
    showBaseInfo();
    cout << "移动磁道序列: ";
    int min = 0x7fffffff;
    int index = 0;
    while (!requests.empty()) {
        for (int i = 0; i < requests.size(); ++i) {
            if (abs(requests[i] - current) <= min) {
                //如果相等，处于当前磁道移动方向相同的优先
                if (abs(requests[i] - current) == min) {
                    if (direction) {
                        if (requests[i] < current) {
                            continue;
                        }
                    } else {
                        if (requests[i] > current) {
                            continue;
                        }
                    }
                }
                min = abs(requests[i] - current);
                index = i;
            }
        }
        cout << requests[index] << " ";
        totalMoveNum += abs(requests[index] - current);
        current = requests[index];
        requests.erase(requests.begin() + index);
        min = 0x7fffffff;
    }
    cout << endl;
    cout << "总移动磁道数: " << totalMoveNum << endl;
}