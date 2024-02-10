//Engineer : Ahmed Hazem

#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H
#include <iostream>
using namespace std;

class Doublelinkedlist
{
private :
    struct node
    {
        int item;
        node *next;
        node *previous;
    };
    int length; //total number of elements
    node *lift,*right;
public:
    Doublelinkedlist();
    ~Doublelinkedlist();
    void insert_lift(const int & element);
    void insert_right(const int & element);
    void insert_at_position(const size_t & position,const int & element);
    void searchh(const int & element);
    void remove_lift();
    void remove_right();
    void remove_at_position(const size_t &index);
    void reverse2();
//  void reversee();
    void sort();
    void print_element();
};

#endif
