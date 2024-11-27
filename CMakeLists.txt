cmake_minimum_required(VERSION 3.28)
project(DiskScheduling)

set(CMAKE_CXX_STANDARD 17)

add_executable(DiskScheduling main.cpp
        Disk.cpp
        Disk.h
        DiskFCFS.cpp
        DiskFCFS.h
        DiskSSFT.cpp
        DiskSSFT.h
        DiskSCAN.cpp
        DiskSCAN.h
        Menu.cpp
        Menu.h)
