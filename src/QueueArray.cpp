//Engineer : Ahmed Hazem

#include "QueueArray.h"
#include<iostream>
using namespace std;
QueueArray::QueueArray(int size)//parameterized constructor
{
    this->size=size;
    arr=new int [size=7];
    length=0;
    front=0;
    rear=size-1;
}

QueueArray::~QueueArray()
{
    delete []arr;//deallocate dynamic array from heap
}
bool QueueArray::isempty()
{
    return length==0;
}

bool QueueArray::isfull()
{
    return size==length;
}
void QueueArray::enqueue(const int &element)
{
    if(isfull())
    {
        cout<<"THE QUEUE IS FULL , CAN'T INSERT ==> "<<element<<endl;
    }
    else
    {
        rear=(rear+1)%size;
        arr[rear]=element;
        length++;
    }

}
void QueueArray::dequeue()
{
    if(isempty())
    {
        cout<<"THE QUEUE IS EMPTY , CAN'T REMOVE ANY ELEMENT"<<endl;
    }
    else
    {
        front=(front+1)%size;
        length--;
    }
}
int QueueArray::getsize()
{
    return size;
}
int QueueArray::getfront()
{
    if(isempty())
    {
        cout<<"THE QUEUE IS EMPTY , CAN'T DISPLAY FRONT ELEMENT"<<endl;
    }
    else
    {
        return arr[front];
    }
}
int QueueArray::getrear()
{
    if(isempty())
    {
        cout<<"THE QUEUE IS EMPTY , CAN'T DISPLAY REAR ELEMENT"<<endl;
    }
    else
    {
        return arr[rear];
    }
}
void QueueArray::print()
{
    for(int i=front; i<rear; i=(i+1)%size)
    {
        cout<<arr[i]<<" ";
    }
    cout<<arr[rear]<<endl;
}
