//Engineer : Ahmed Hazem

#include "Singlelinkedlist.h"
#include<iostream>
using namespace std;


Singlelinkedlist::Singlelinkedlist()
{
    length=0;
    right = lift = NULL ;
}

Singlelinkedlist::~Singlelinkedlist()
{
    while(lift!=NULL)
    {
        node*now = lift ;
        lift = lift->next ;
        now = NULL ;
        delete now ;
    }
}
void Singlelinkedlist::insert_lift(const int & element)
{
    node *newnode = new node;
    newnode->item = element;
    if(length == 0)//It will be implemented with the first insert only
    {
        newnode->next=NULL;
        right=lift=newnode;// in the first insert
    }
    else
    {
        newnode->next=lift;
        lift=newnode;
    }
    length++;

}
void Singlelinkedlist::insert_right(const int & element)
{
    node *newnode=new node;
    newnode->item=element;
    if(length==0)
    {
        newnode->next=NULL;
        right=lift=newnode;
    }
    else
    {
        newnode->next=NULL;
        right->next=newnode;

        right=newnode;
    }
    length++;

}
void Singlelinkedlist::insert_at_position(const size_t & position, const int & element)
{
    if(position>length)//if i have 5 index , length ==>6
    {
        cout<<"ERROR : OUT OF RANGE"<<endl;
    }
    else if(position==0)
    {
        insert_lift(element);//when index is 0 ==> insert left
    }
    else if(position==length)
    {
        insert_right(element);//when (index=length )==>insert right
    }
    else
    {
        node *newnode = new node;
        newnode->item=element;
        node *now=lift;
        for(int i=0; i<(position-1); i++)//number of loop verrrryyy important
        {
            now=now->next;
        }
        newnode->next=now->next;
        now->next=newnode;
        length++;
    }
}
void Singlelinkedlist::searchh(const int & element)
{
    if(length==0)
    {
        cout<<"the list is empty"<<endl;
        return;
    }
    else
    {
        node *current = lift;
        for(int i=0; i<length; i++)
        {
            if(current->item==element)
            {
                cout<<" index of "<<element<<" is ==> "<<i<<endl;
                return ;
            }
            current=current->next;
        }
    }
    cout<<element<<" not found in my elements "<<endl;
}
void Singlelinkedlist::reversee()
{
    node *previous=NULL;//initial value
    node *current=lift;
    node *next;
    while(current!=NULL)
    {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    lift = previous;// when current is equal NULL

}
void Singlelinkedlist::remove_lift()
{
    if(length==0)
    {
        cout<<"THE LIST IS EMPTY"<<endl;
    }
    else if(length==1)
    {
        right=lift=NULL;
        delete lift;
        delete right;
        length--;
    }
    else
    {
        node* after=lift;
        lift=lift->next;
        after->next=NULL;
        delete after;
        length--;
    }
}
void Singlelinkedlist::remove_right()
{
    if(length==0)
    {
        cout<<"THE LIST IS EMPTY"<<endl;
    }
    else if(length==1)
    {
        right=lift=NULL;
        delete lift; 
        delete right;
        length--;

    }
    else
    {
        node *now=lift;
        for(int i=1; i<length-1; i++)//while(current->next!=right)
        {
            now=now->next;
        }
        right=NULL;
        delete right;
        right=now;
        /*right=now;
        now->next=NULL;
        delete now->next;*/
        length--;

    }
}
void Singlelinkedlist::remove_at_position(const size_t &index)
{
    if(index > length)
    {
        cout<<"ERROR : OUT OF RANGE "<<endl;
    }
    else if(index==0)
    {
        remove_lift();
    }
    else if(index==length-1)
    {
        remove_right();
    }
    else
    {
        node* current = lift , *after = lift->next ,*mydelete ;
        for(int i=0; i<index-1; i++)
        {
            current = current->next;
            after = after->next;
        }
        after = after->next;
        current->next=after;
        mydelete = current->next;
        mydelete = NULL;
        delete mydelete;
        length--;
    }
}


void Singlelinkedlist::print_element()
{
    node *print;
    print = lift;
    for(int i = 0 ; i<length ; i++)
    {
        cout<<print->item<<" " ;
        print = print->next ;
    }
    cout<<endl ;
}

