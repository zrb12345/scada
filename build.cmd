@echo off
title qmake build prompt

qmake E:\work\C++\scada\scada1\scada1.pro -o E:\work\C++\scada\scada1\Build -spec win32-g++ "CONFIG+=debug" "CONFIG+=qml_debug"
cd E:\work\C++\scada\scada1\Build
mingw32-make.exe -f E:\work\C++\scada\scada1/Build/Makefile.Debug qmake_all
mingw32-make.exe -j12

move scada1.exe .\debug
cd debug
windeployqt.exe TSSW_frame.exe
