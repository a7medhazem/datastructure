//Engineer : Ahmed Hazem

#ifndef STACKARRAY_H
#define STACKARRAY_H
#include <iostream>
using namespace std;


class StackArray
{
private:
    int *arr;//pointer to access ==> dynamic array
    size_t size;//size of dynamic array
    int top;//ptr ==>stand on the last value is added
public:
    void push(int val);
    void pop();
    void get_top();//value of topppp
    int get_topp();
    bool is_Full();
    bool is_Empty();
    void print();
    StackArray(size_t size);
    ~StackArray();


};

#endif // STACKARRAY_H
