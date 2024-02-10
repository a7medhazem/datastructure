//Engineer : Ahmed Hazem

#include "StackArray.h"
#include <iostream>
using namespace std;

StackArray::StackArray( size_t size)//par const
{
    top=-1;//initial value
    this->size=size;
    arr=new int[size=20];// عصفوربن بحجر def & par constructor
}


StackArray::~StackArray()
{
    delete [] arr;//deallocate memorey
}
void StackArray::push(int val)
{
    if(is_Full())
    {
        cout<<"the stack is full , cant insert element "<<val<<endl;
    }
    else
    {
        top++;
        arr[top]=val;
    }
}
void StackArray::pop()
{
    if(is_Empty())
    {
        cout<<"stack is empty , can't find any element to remove it "<<endl;
    }
    else
    {
        top--;
    }
}
void StackArray::get_top()
{
    if(is_Empty())
    {
        cout<<"stack is empty , can't find any element to return the top"<<endl;
    }
    else
    {
        cout<<" the value of top is : "<<arr[top]<<endl;
    }
}
int StackArray::get_topp()//value of topppp
{
    if(is_Empty())
    {
        cout<<"stack is empty , can't find the top"<<endl;
    }
    else
    {
        return arr[top];

    }
}

bool StackArray::is_Full()
{
   return size==top+1;
}
bool StackArray::is_Empty()
{
    return (top==-1);
}
void StackArray::print()
{
    cout<<"size of stack is ==> "<<size<<endl;
    cout<<"size of element is ==> "<<top+1<<endl;
    cout<<"the elements of the stack ==> ";
    for(int i=top ; i>=0 ; i--)//LIFO ==> last in first out
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
