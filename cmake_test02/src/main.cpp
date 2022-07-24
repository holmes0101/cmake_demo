#include <iostream>
#include "calculatorInferface.h"
#include <dlfcn.h>
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
    void* soHandle = dlopen("/Users/wangyonghua/VS-code-projects/cmake_test04/3rlib/build/lib/x86/libsimpleCalculator.dylib", RTLD_NOW);
    if(soHandle == nullptr){
        std::cout << "open so failed" << std::endl;
        return -1;
    }
    while(cnt < MAX_CNT){
        cnt += 1;
        typedef int (*InitHandleFun)(void**);
        InitHandleFun initHandleFun = (InitHandleFun)dlsym(soHandle, "InitHandle");
        if(initHandleFun == nullptr){
            std::cout << "initHandleFun is nullptr" << std::endl;
            break;
        }
        ret = initHandleFun(&handle);
        if(ret != 0){
            std::cout << "InitHandle Failed" << std::endl;
        }
        
        //test +
        param.inputInfo->inputOp = "+";

        typedef int (*ProcessFun)(void*, Calculator::Parameter*);
        ProcessFun processFun = (ProcessFun)dlsym(soHandle, "Process");
        if(processFun == nullptr){
            std::cout << "processFun is nullptr" << std::endl;
            break;
        }
        ret = processFun(handle, &param);
        std::cout<< "add Process result:" << ret << std::endl;
        std::cout << "add operator result: [" << param.outputInfo->x << "," << param.outputInfo->y << "]" << std::endl;

        // test -
        param.inputInfo->inputOp = "-";
        ret = processFun(handle, &param);
        std::cout << "sub Process result:" << ret << std::endl;
        std::cout << "sub operator result: [" << param.outputInfo->x << "," << param.outputInfo->y << "]" << std::endl;

        typedef int (*ResetFun)(void*);
        ResetFun resetFun = (ResetFun)dlsym(soHandle, "Reset");
        if(resetFun == nullptr){
            std::cout << "resetFun is nullptr" << std::endl;
            break;
        }
        ret = resetFun(handle);
        std::cout << "Reset Result: " << ret << std::endl;

        typedef int (*DestoryFun)(void*);
        DestoryFun destoryFun = (DestoryFun)dlsym(soHandle, "Destory");
        if(destoryFun == nullptr){
            std::cout<< "destoryFun is nullptr" << std::endl;
            break;
        }
        ret = destoryFun(&handle);
        std::cout << "Destory Result: " << ret << std::endl;
    }
    dlclose(soHandle);

    return 0;
}