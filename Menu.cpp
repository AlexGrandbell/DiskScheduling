//
// Created by AlexGrandbell on 24-11-27.
//

#include "Menu.h"

//打印菜单
void Menu::PrintMenu() {
    int choice;
    while (true) {
        cout << "\n当前算法: ";
        switch (mode) {
            case 1:
                cout << "FCFS先来先服务算法" << endl;
                break;
            case 2:
                cout << "SSFT最短寻道时间优先算法" << endl;
                break;
            default:
                cout << "SCAN扫描算法" << endl;
                break;
        }
        cout << "当前磁道数: " << current << endl;
        cout << "当前磁头移动方向: " << (direction ? "向外" : "向内") << endl;
        cout << "当前请求序列: ";
        for (int i = 0; i < requests.size(); ++i) {
            cout << requests[i] << " ";
        }
        cout << endl;
        cout << "/**---------菜单---------**\\" << endl;
        cout << "1.设置请求序列" << endl;
        cout << "2.设置当前磁道" << endl;
        cout << "3.设置磁头初始移动方向" << endl;
        cout << "4.选择算法" << endl;
        cout << "5.运行" << endl;
        cout << "0.退出" << endl;
        cout << "/-**------菜单结束-------**\\" << endl;
        cout << "请选择:";
        cin >> choice;
        switch (choice) {
            case 1:
                setRequests();
                break;
            case 2:
                setCurrent();
                break;
            case 3:
                setDirection();
                break;
            case 4:
                setMode();
                break;
            case 5:
                run();
                break;
            case 0:
                return;
            default:
                cout << "输入错误，请重新输入" << endl;
        }
        cout << "按下回车继续...";
        getchar();//吃掉缓冲区中的回车
        getchar();
    }
}

//设置请求序列
void Menu::setRequests() {
    requests.clear();
    cout << "请输入请求序列(以-1结束):";
    int request;
    while (true) {
        cin >> request;
        if (request <= 0) {
            break;
        }
        requests.push_back(request);
    }
}

//设置当前磁道
void Menu::setCurrent() {
    cout << "请输入当前磁道:";
    cin >> current;
    if (current < 0) {
        cout << "输入错误，请重新输入" << endl;
        setCurrent();
    }
}

//设置磁头初始移动方向
void Menu::setDirection() {
    cout << "请选择磁头初始移动方向(1-向外 0-向内):";
    cin >> direction;
    if (direction != 0 && direction != 1) {
        cout << "输入错误，请重新输入" << endl;
        setDirection();
    }
}

//选择算法
void Menu::setMode() {
    cout << "请选择算法(1-FCFS先来先服务算法 2-SSFT最短寻道时间优先算法 3-SCAN扫描算法):";
    cin >> mode;
    if (mode != 1 && mode != 2 && mode != 3) {
        cout << "输入错误，请重新输入" << endl;
        setMode();
    }
}

//运行
void Menu::run() {
    switch (mode) {
        case 1: {
            DiskFCFS diskFCFS(requests, direction, current);
            diskFCFS.run();
            break;
        }
        case 2: {
            DiskSSFT diskSSFT(requests, direction, current);
            diskSSFT.run();
            break;
        }
        default: {
            DiskSCAN diskSCAN(requests, direction, current);
            diskSCAN.run();
            break;
        }
    }
}