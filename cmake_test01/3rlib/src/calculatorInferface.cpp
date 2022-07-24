#include <iostream>
#include "calculator.h"

namespace Calculator{

int InitHandle(void** handle)
{
    std::cout << "enter InitHandle" << std::endl;
    if(handle == nullptr){
        std::cout << "handle is nullptr" << std::endl;
        return -1;
    }
    SimpleCalculator* object = new(std::nothrow) SimpleCalculator();
    if(object == nullptr){
        std::cout << "InitHandle calloc Failed" << std::endl;
        return -1;
    }
    int ret = object->Init();
    *handle = reinterpret_cast<void*>(object);
    return ret;
}

int Process(void* handle, struct Parameter* param)
{
    std::cout << "enter Process" << std::endl;
    if(handle == nullptr){
        std::cout << "handle is nullptr" << std::endl;
        return -1;
    }
    if(param == nullptr){
        std::cout << "Process param is nullptr" << std::endl;
        return -1;
    }
    SimpleCalculator* object = reinterpret_cast<SimpleCalculator*>(handle);
    int ret = 0;
    do{
        ret = object->Process(param);
        if(ret != 0){
            std::cout << "Process Failed" << std::endl; 
        }
    }while(0);
    return ret;
}

int Reset(void* handle)
{
    std::cout << "enter Reset" << std::endl;
    if(handle == nullptr){
        std::cout << "handle is nullptr" << std::endl;
        return -1;
    }
    SimpleCalculator* object = reinterpret_cast<SimpleCalculator*>(handle);
    int ret = 0;
    do{
        ret = object->Reset();
        if(ret != 0){
            std::cout << "Process Reset" << std::endl; 
        }
    }while(0);
    return ret;
}

int Destory(void** handle)
{
    std::cout << "enter Destory"<< std::endl;
    if(handle == nullptr){
        std::cout << "handle is nullptr" << std::endl;
        return -1;
    }
    if(*handle == nullptr){
        std::cout << "*handle is nullptr" << std::endl;
        return -1;
    }
    SimpleCalculator* object = reinterpret_cast<SimpleCalculator*>(*handle);
    int ret = 0;
    do{
        ret = object->Destory();
        if(ret != 0){
            std::cout << "Process Destory" << std::endl; 
        }
    }while(0);
    if(object){
        delete object;
        object = nullptr;
    }
    *handle = nullptr;
    return ret;
}

}