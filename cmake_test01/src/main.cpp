#include <iostream>
#include "calculatorInferface.h"

int main()
{
    Calculator::Point* outputResult = (Calculator::Point*)calloc(1, sizeof(Calculator::Point));
    if(outputResult == nullptr){
        std::cout << "outputResult malloc Failed" << std::endl;
        return -1;
    }
    Calculator::InputInfo* inputInfo = (Calculator::InputInfo*)calloc(1, sizeof(Calculator::InputInfo));
    if(inputInfo == nullptr){
        std::cout << "inputInfo malloc Failed" << std::endl;
        return -1;
    }
    Calculator::Parameter param;
    param.inputInfo = inputInfo;
    param.outputInfo = outputResult;
    

    // set inputinfo
    inputInfo->inputOp = "+";
    inputInfo->inputPoint[0].x = 2;
    inputInfo->inputPoint[0].y = 5;
    inputInfo->inputPoint[1].x = 3;
    inputInfo->inputPoint[1].y = 6;

    std::cout << "test + opertaor" << std::endl;
    void* handle = nullptr;
    int ret = 0;
    int cnt = 0;
    int MAX_CNT = 10;
    while(cnt < MAX_CNT){
        cnt += 1;
        ret = Calculator::InitHandle(&handle);
        if(ret != 0){
            std::cout << "InitHandle Failed" << std::endl;
        }
        
        //test +
        param.inputInfo->inputOp = "+";
        ret = Process(handle, &param);
        std::cout<< "add Process result:" << ret << std::endl;
        std::cout << "add operator result: [" << param.outputInfo->x << "," << param.outputInfo->y << "]" << std::endl;

        // test -
        param.inputInfo->inputOp = "-";
        ret = Calculator::Process(handle, &param);
        std::cout << "sub Process result:" << ret << std::endl;
        std::cout << "sub operator result: [" << param.outputInfo->x << "," << param.outputInfo->y << "]" << std::endl;

        ret = Calculator::Reset(handle);
        std::cout << "Reset Result: " << ret << std::endl;

        ret = Calculator::Destory(&handle);
        std::cout << "Destory Result: " << ret << std::endl;
    }

    return 0;
}