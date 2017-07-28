@echo off
@setlocal

g++ -std=c++11 -o main src\*.cpp %*
main.exe
del main.exe
