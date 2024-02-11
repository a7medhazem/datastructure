//Engineer : Ahmed Hazem

#ifndef STACKLINKEDLIST_H
#define STACKLINKEDLIST_H
#include<iostream>
using namespace std;

class StackLinkedList
{
private:
    struct node
    {
        int  item;
        node *next;

    };
    node *top;
    int length;//number of elements
public:
    void pop();
    void push(int value);
    void get_top();//value of topppp
    int get_topp();
    bool is_Full();
    bool is_Empty();
    void sortt();
    void print();
    StackLinkedList();
    ~StackLinkedList();
};

#endif // STACKLINKEDLIST_H
