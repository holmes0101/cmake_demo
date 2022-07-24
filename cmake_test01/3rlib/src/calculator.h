#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <map>
#include <vector>
#include "calculatorInferface.h"

namespace Calculator
{

class SimpleCalculator{

public:
    SimpleCalculator();
    ~SimpleCalculator();
    int Init();
    int Process(struct Parameter* param);
    int Reset();
    int Destory();

private:
    int Add(struct Point* a, struct Point* b);
    int Sub(struct Point* a, struct Point* b);

private:
    bool mInit = false;
    Point* mResult = nullptr;
};
    
} // namespace Calculator

#endif