//Engineer : Ahmed Hazem

#include "Doublelinkedlist.h"
#include <iostream>
using namespace std;
Doublelinkedlist::Doublelinkedlist()
{
    length=0;
    right = lift = NULL;//you can remove it ==> easy

}

Doublelinkedlist::~Doublelinkedlist()//deallocate memorey
{
    while(lift!=NULL)
    {
        node*now=lift;
        lift=lift->next;
        now=NULL;
        delete now;
    }
}
void Doublelinkedlist::insert_lift(const int & element)
{
    node *newnode = new node;
    newnode->item=element;
    if(length==0)//It will be implemented with the first the first insert only
    {
        newnode->next=NULL;
        newnode->previous=NULL;

        right=lift=newnode;
    }
    else
    {
        newnode->next=lift;
        lift->previous=newnode;
        newnode->previous=NULL;
        lift=newnode;
    }
    length++;
}
void Doublelinkedlist::insert_right(const int & element)
{
    node *newnode=new node;
    newnode->item=element;
    if(length==0)
    {
        newnode->next=NULL;
        newnode->previous=NULL;
        right=lift=newnode;
    }
    else
    {
        newnode->next = NULL ;
        newnode->previous = right ;
        right->next = newnode ;
        right = newnode ;
    }
    length++ ; //don't forget this statement , please

}
void Doublelinkedlist::insert_at_position(const size_t & position,const int & element)
{
    if(position>length)
    {
        cout<<"ERROR : OUT OF RANGE"<<endl;
    }
    else if(position==0)
    {
        insert_lift(element);
    }
    else if(position==length)
    {
        insert_right(element);
    }
    else
    {
        node *newnode = new node;
        newnode->item=element;

        node *now=lift,*after;
        for(int i=0; i<(position-1); i++)//number of loop verrrryyy important
        {
            now=now->next;
        }
        after=now->next;

        newnode->next = after ;
        after->previous = newnode ;
        newnode->previous = now ;
        now->next = newnode ;
        length++ ;
    }

}
void Doublelinkedlist::searchh(const int & element)
{
    node *current = lift;

    for(int i=0; i<length; i++)
    {
        if(current->item == element)
        {
            cout<<"the index of element("<<element<<") is ==> "<<i<<endl;
            return ;//end this function

        }
        current=current->next;
    }
    cout<<element<<" NOT FOUND IN MY ELEMENTS "<<endl;
}
void Doublelinkedlist::remove_lift()
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
        node *now = lift ;
        lift = lift->next ;
        now = NULL ;
        delete now ;
        lift->previous = NULL ;
        length-- ;
    }
}
void Doublelinkedlist::remove_right()
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
        node * current=right;
        right=right->previous;
        right->next=NULL;
        current=NULL;
        delete current;
        length--;
    }
}
void Doublelinkedlist::remove_at_position(const size_t &index)//size_t unsigned integer , impossible index<0
{
    if(length==0)
    {
        cout<<"list is empty "<<endl;
    }
    else
    {


        if(index > length)
        {
            cout<<"error : your index is out of range "<<endl;
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
            node* current=lift,*del=current->next,*after=del->next;
            for(int i=0; i<index-1; i++)
            {
                current=current->next;
                del=del->next;
                after=after->next;
            }
            current->next=after;
            after->previous=current;
            del=NULL;
            delete del;
            length--;
        }
    }
}
/* ==> another way
void Doublelinkedlist::reversee()
{
    node*now=right;
    for(int i=0; i<length; i++)
    {
        cout<<now->item<<" ";
        now=now->previous;
    }
    cout<<endl;

}*/
void Doublelinkedlist::reverse2()
{
    node *before=lift;
    node *now=before->next;
    node *after=now->next;
    if(before==lift)//executed one time
    {
        before->previous==now;
        before->next=NULL;
    }
    while(now!=NULL)
    {
        now->next=before;
        now->previous=after;
        before=now;
        now=after;
        if(after!=NULL)//to stop in ==> null , if it walk ==> happen error ;
        {
            after=after->next;
        }
    }

    //swaping time between right & lift .
    node *temp=right;
    right=lift;
    lift=temp;
    temp=NULL;
    delete temp;
}


void Doublelinkedlist::sort()//by ascending order
{
    node *current = lift ;
    node *after ;
    for(int i=0 ; i<length ; i++)//while(current!=NULL)
    {
        after=current->next;
        for(int x = i+1 ; x<length ; x++)//while(after!=NULL)
        {
            if( (current->item) < (after->item) )
            {
                after = after->next ;
            }
            else
            {
                swap(current->item, after->item) ;
                after= after->next ;
            }
        }
        current = current->next ;
    }
}


void Doublelinkedlist::print_element()
{
    node *print=lift;
    for(int i=0; i<length; i++)
    {
        cout<<print->item<<" ";
        print=print->next;
    }
    cout<<endl;
}
