#include "calculator.h"
#include <iostream>

namespace Calculator
{
    
SimpleCalculator::SimpleCalculator()
{
    std::cout << "enter SimpleCalculator()" << std::endl;
}

SimpleCalculator::~SimpleCalculator()
{
    std::cout << "enter ~SimpleCalculator()" << std::endl;
}

int SimpleCalculator::Init()
{
    std::cout << "enter SimpleCalculator::Init()" << std::endl;
    mResult = (struct Point*)calloc(1, sizeof(struct Point));
    if(mResult == nullptr){
        std::cout << "malloc result Failed" << std::endl;
        return -1;
    }
    mInit = true;
    return 0;
}

int SimpleCalculator::Process(struct Parameter* param)
{
    std::cout << "enter SimpleCalculator::Process()" << std::endl;
    if(param == nullptr){
        std::cout << "SimpleCalculator::Process() param is nullptr" << std::endl;
        return -1;
    }
    if(param->inputInfo == nullptr || param->outputInfo == nullptr){
        std::cout << "SimpleCalculator::Process() inputInfo:" << param->inputInfo << " is nullptr or outputInfo:" << param->outputInfo << " is nullptr" << std::endl;
        return -1;
    }
    if(!mInit){
        std::cout << "SimpleCalculator init Failed" << std::endl;
        return -1;
    }
    int ret = 0;
    do{
        if(param->inputInfo->inputOp == "+"){
            ret = Add(param->inputInfo->inputPoint, param->inputInfo->inputPoint + 1);
        }else if(param->inputInfo->inputOp == "-"){
            ret = Sub(param->inputInfo->inputPoint, param->inputInfo->inputPoint + 1);
        }else{
            std::cout << "Not Support this operator:" << param->inputInfo->inputOp << std::endl;
        }
    }while(0);
    if(ret != 0){
        std::cout << "SimpleCalculator Process() error" << std::endl;
        return -1;
    }else{
        std::cout << "SimpleCalculator Process() Success" << std::endl;
        std::cout << "mResult Point is [" << mResult->x << "," << mResult->y << "]" << std::endl;
        memcpy(param->outputInfo, mResult, sizeof(struct Point));
    }
    return 0;
}

int SimpleCalculator::Add(struct Point* a, struct Point* b)
{
    std::cout << "enter SimpleCalculator::Add()" << std::endl;
    if(a == nullptr || b == nullptr){
        std::cout << "fun Add a=" << a << " b=" << b << std::endl;
        return -1;
    }
    mResult->x = a->x + b->x;
    mResult->y = a->y + b->y;
    return 0;
}

int SimpleCalculator::Sub(struct Point* a, struct Point* b)
{
    std::cout << "enter SimpleCalculator::Sub()" << std::endl;
    if(a == nullptr || b == nullptr){
        std::cout << "fun Sub a=" << a << " b=" << b << std::endl;
        return -1;
    }
    mResult->x = a->x - b->x;
    mResult->y = a->y - b->y;
    return 0;
}

int SimpleCalculator::Reset()
{
    std::cout << "enter SimpleCalculator::Reset()" << std::endl;
    if(!mInit){
        std::cout << "SimpleCalculator init Failed" << std::endl;
        return -1;
    }
    memset(mResult, 0x00, sizeof(struct Point));
    return 0;
}

int SimpleCalculator::Destory()
{
    std::cout << "enter SimpleCalculator::Destory()" << std::endl;
    if(!mInit){
        std::cout << "SimpleCalculator init Failed" << std::endl;
        return -1;
    }
    if(mResult){
        free(mResult);
        mResult = nullptr;
    }
    return 0;
}

} // namespace Calculator

