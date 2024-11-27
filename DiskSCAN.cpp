//
// Created by AlexGrandbell on 24-11-27.
//

#include "DiskSCAN.h"

//扫描算法（电梯算法）
void DiskSCAN::run() {
    cout << "扫描算法" << endl;
    showBaseInfo();
    cout << "移动磁道序列: ";
    vector<int> left;
    vector<int> right;
    for (int i = 0; i < requests.size(); ++i) {
        if (requests[i] < current) {
            left.push_back(requests[i]);
        } else {
            right.push_back(requests[i]);
        }
    }
    sort(left.begin(), left.end());
    sort(right.begin(), right.end());
    if (direction) {//向外
        for (int i = 0; i < right.size(); ++i) {
            cout << right[i] << " ";
            totalMoveNum += abs(right[i] - current);
            current = right[i];
        }
        for (int i = left.size() - 1; i >= 0; --i) {
            cout << left[i] << " ";
            totalMoveNum += abs(left[i] - current);
            current = left[i];
        }
    } else {
        for (int i = left.size() - 1; i >= 0; --i) {
            cout << left[i] << " ";
            totalMoveNum += abs(left[i] - current);
            current = left[i];
        }
        for (int i = 0; i < right.size(); ++i) {
            cout << right[i] << " ";
            totalMoveNum += abs(right[i] - current);
            current = right[i];
        }
    }
    cout << endl;
    cout << "总移动磁道数: " << totalMoveNum << endl;
}