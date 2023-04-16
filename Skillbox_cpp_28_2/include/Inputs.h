#pragma once
#include <iostream>
#include <mutex>
#include <string>

class Validator {
public:
    static bool isNumberInt(std::string str);
    static bool isNumberReal(std::string str);
};

class Inputs{
public:
    static std::mutex terminal_access;
    static std::string inputStr(std::string prompt);
    static double inputDouble(const std::string& prompt);
    static double inputPosDouble(const std::string& prompt);
    static int inputInt(const std::string& prompt);
    static void print(std::string str);
};
