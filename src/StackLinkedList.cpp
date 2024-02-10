//Engineer : Ahmed Hazem

#include "StackLinkedList.h"
#include<iostream>
using namespace std;

StackLinkedList::StackLinkedList()
{
    top=NULL;
    length=0;
}

StackLinkedList::~StackLinkedList()
{
}
bool StackLinkedList::is_Empty()
{
    if(length==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void StackLinkedList::push(int value)
{
    node *newnode=new node;
    newnode->item=value;
    newnode->next=top;
    top=newnode;
    length++;
}
void StackLinkedList::pop()
{
    if(is_Empty())
    {
        cout<<"error : the stack is empty , can't delete any element "<<endl;
    }
    else
    {
        node *current=top;
        top=top->next;
        current->next=NULL;
        delete current;
        length--;
    }
}
void StackLinkedList::get_top()
{
    cout<<"the value of the top is ==> "<<top->item<<endl;
}
int StackLinkedList::get_topp()
{
    return (top->item);
}
void StackLinkedList::sortt()
{
    node *now=top;
    node *after;
    for(int i=0; i<length; i++)
    {
        after=now->next;

        for(int o=i+1; o<length; o++ )
        {
            if((now->item)>(after->item))
            {
                swap(now->item,after->item);
                //after=after->next;
            }
            after=after->next;
        }
        now=now->next;
    }
}

void StackLinkedList::print()
{
    cout<<"elements of stack is ==> ";
    node *now=top;
    for(int i=length-1; i>=0; i--)//while(current!=NULL)
    {
        cout<<now->item<<" ";
        now=now->next;
    }
    cout<<endl;
    cout<<"========================================="<<endl;
}
