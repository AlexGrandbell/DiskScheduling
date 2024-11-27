//
// Created by AlexGrandbell on 24-11-27.
//

#include "Disk.h"

//打印基本信息
void Disk::showBaseInfo() {
    cout << "请求序列: ";
    for (int i = 0; i < requests.size(); ++i) {
        cout << requests[i] << " ";
    }
    cout << endl;
    cout << "磁头移动方向: " << (direction ? "向外" : "向内") << endl;
    cout << "当前磁道: " << current << endl;
}