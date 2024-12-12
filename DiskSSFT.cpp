//
// Created by AlexGrandbell on 24-11-27.
//

#include "DiskSSFT.h"

//最短寻道时间优先算法
void DiskSSFT::run() {
    cout << "最短寻道时间优先算法" << endl;
    showBaseInfo();
    cout << "移动磁道序列: "<<current<< " ";
//    int min = 0x7fffffff;
//    int index = 0;
//    while (!requests.empty()) {
//        for (int i = 0; i < requests.size(); ++i) {
//            if (abs(requests[i] - current) <= min) {
//                //如果相等，处于当前磁道移动方向相同的优先
//                if (abs(requests[i] - current) == min) {
//                    if (direction) {
//                        if (requests[i] < current) {
//                            continue;
//                        }
//                    } else {
//                        if (requests[i] > current) {
//                            continue;
//                        }
//                    }
//                }
//                min = abs(requests[i] - current);
//                index = i;
//            }
//        }
//        cout << requests[index] << " ";
//        totalMoveNum += abs(requests[index] - current);
//        current = requests[index];
//        requests.erase(requests.begin() + index);
//        min = 0x7fffffff;
//    }
    //一个有序的请求序列
    vector<int> sortedRequests=requests;
    sort(sortedRequests.begin(),sortedRequests.end());
    //一个已经遍历的标记数组
    vector<bool> flag(sortedRequests.size(), false);

    int index=0;
    int sum=0;
    int min = abs(sortedRequests[0] - current);
    for (int i = 1; i < sortedRequests.size(); ++i) {
        if (abs(sortedRequests[i] - current) <= min) {
            //如果相等，处于当前磁道移动方向相同的优先
            if (abs(sortedRequests[i] - current) == min) {
                if (direction) {
                    if (sortedRequests[i] < current) {
                        continue;
                    }
                } else {
                    if (sortedRequests[i] > current) {
                        continue;
                    }
                }
            }
            min = abs(sortedRequests[i] - current);
            index = i;
        }
    }
    cout << sortedRequests[index] << " ";
    totalMoveNum += abs(sortedRequests[index] - current);
    current = sortedRequests[index];
    flag[index] = true;
    sum++;
    while (sum < sortedRequests.size()) {
        int left = 0;
        int right = 0;
        int minleft = 0x7fffffff;
        int minright = 0x7fffffff;
        //朝左边最小的一个
        for (int i = index - 1; i >= 0; --i) {
            if (!flag[i] && abs(sortedRequests[i] - current) <= minleft) {
                minleft = abs(sortedRequests[i] - current);
                left = i;
                break;
            }
        }
        //朝右边最小的一个
        for (int i = index + 1; i < sortedRequests.size(); ++i) {
            if (!flag[i] && abs(sortedRequests[i] - current) <= minright) {
                minright = abs(sortedRequests[i] - current);
                right = i;
                break;
            }
        }
        //找到最小的一个
        if (minleft < minright) {
            cout << sortedRequests[left] << " ";
            totalMoveNum += abs(sortedRequests[left] - current);
            current = sortedRequests[left];
            flag[left] = true;
            index = left;
        } else if (minleft > minright) {
            cout << sortedRequests[right] << " ";
            totalMoveNum += abs(sortedRequests[right] - current);
            current = sortedRequests[right];
            flag[right] = true;
            index = right;
        }else{//左右相等看方向
            if (!direction) {
                cout << sortedRequests[right] << " ";
                totalMoveNum += abs(sortedRequests[right] - current);
                current = sortedRequests[right];
                flag[right] = true;
                index = right;
            } else {
                cout << sortedRequests[left] << " ";
                totalMoveNum += abs(sortedRequests[left] - current);
                current = sortedRequests[left];
                flag[left] = true;
                index = left;
            }
        }
        sum++;
    }

    cout << endl;
    cout << "总移动磁道数: " << totalMoveNum << endl;
}