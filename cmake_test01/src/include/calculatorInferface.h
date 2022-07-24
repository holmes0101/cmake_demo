#ifndef CALCULATOR_INFERFACE_H
#define CALCULATOR_INFERFACE_H

#define MY_EXTERN extern "C"
#include <string>

namespace Calculator
{

struct Point{
    int x = 0;
    int y = 0;
};

struct InputInfo{
    Point inputPoint[2];
    std::string inputOp = "+";
};
struct Parameter{
    InputInfo* inputInfo = nullptr;
    Point* outputInfo = nullptr; 
};

MY_EXTERN int InitHandle(void** handle);

MY_EXTERN int Process(void* handle, struct Parameter* param);

MY_EXTERN int Reset(void* handle);

MY_EXTERN int Destory(void** handle);
    
} // names

#endif