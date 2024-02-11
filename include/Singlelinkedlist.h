//Engineer : Ahmed Hazem

#ifndef SINGLELINKEDLIST_H
#define SINGLELINKEDLIST_H
#include <iostream>
using namespace std;

class Singlelinkedlist
{
private :
    struct node
    {
        int item;
        node *next;
    };
    int length;//number of element
    node *lift,*right;
    Singlelinkedlist();
    ~Singlelinkedlist();
    void insert_lift(const int & element);
    void insert_right(const int & element);
    void insert_at_position(const size_t & position,const int & element);
    void searchh(const int & element);
    void reversee();
    void remove_lift();
    void remove_right();
    void remove_at_position(const size_t &index);
    void print_element();
};

#endif // SINGLELINKEDLIST_H
