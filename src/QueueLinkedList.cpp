//Engineer : Ahmed Hazem

#include "QueueLinkedList.h"
#include<iostream>
using namespace std;
QueueLinkedList::QueueLinkedList()
{
    front=rear=NULL;
    length=0;
}
QueueLinkedList::~QueueLinkedList()//deallocate dynamic array
{
    node *now=front;
    while(now!=NULL)
    {
        node *del=now;
        del->next=NULL;
        delete del;
        now=now->next;
    }
}
bool QueueLinkedList::isempty()
{
    return length==0;
}
void QueueLinkedList::enqueue(const int &element)
{
    node*newnode =new node;
    newnode->item=element;
    newnode->next=NULL;
    if(isempty())//executed one time when adding first element
    {
        front=rear=newnode;// 3 pointers point to this element(first element)
    }
    else
    {
        rear->next=newnode ;
        rear=newnode;
    }
    length++;
}
void QueueLinkedList::dequeue()
{
    if(isempty())
    {
        cout<<"THE QUEUE IS EMPTY , CAN'T REMOVE ITEMS"<<endl;
    }
    else
    {
        node *now = front;
        front=front->next;
        now->next=NULL;
        delete now;
        length--;
    }
}
int QueueLinkedList::getsize()
{
    return length;
}
int QueueLinkedList::getfront()
{
    return (front->item);
}
int QueueLinkedList::getrear()
{
    return (rear->item);
}
void QueueLinkedList::print()
{
    if(isempty())
    {
        cout<<"THE QUEUE IS EMPTY , CAN'T DISPLAY ITEMS"<<endl;
    }
    else
    {
        node *print = front;
        for(int i=0; i<length; i++)
        {
            cout<<print->item<<" ";
            print=print->next;
        }
        cout<<endl;
    }
}
void QueueLinkedList::clear()//deallocate all elements
{
    if(isempty())
    {
        cout<<"the queue is empty , can't clear items;"<<endl;
    }
    else
    {
        node *now=front;
        while(now!=NULL)
        {
            node *del= now;
            now= now->next;
            del->next=NULL;
            delete del;
            length--;
        }
    }
}
