//Engineer : Ahmed Hazem
#include "Array.h"
#include<algorithm>
#include<iostream>
using namespace std;
Array::Array(int sizee)//parametrized constructor
{

    this->sizee=sizee;
    arr=new int[sizee];
    length = 0;
}
Array::Array()//default constructor
{
    arr=new int[10];
    sizee=10;
    length = 0;
}
void Array::insert_end(int element)
{
    if(is_full())
    {
        cout<<"THE ARRAY IS FULL CAN'T INSERT  ==> "<<element<<endl;
    }
    else
    {
        arr[length]=element;
        length++;
    }
}
int Array::getsize()
{
    return length;
}
void Array::print()
{
    for(int i=0; i<length; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
bool Array::is_full()
{
    return length==sizee;
}
void Array::insert_positin(int pos, int element)
{
    if(is_full())
    {
        cout<<"THE ARRAY IS FULL , CAN'T INSERT ==> "<<element<<endl;
    }
    else if(pos<0||pos>=sizee)
    {
        cout<<"ERROR : YOUR INDEX OUT OF RANGE "<<endl;
    }
    else
    {
        for(int i=length; i>pos; i--)
        {
            arr[i]=arr[i-1];
        }
        arr[pos]=element;
        length++;

    }
}
bool Array::isempty()
{
    if(length==0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Array::remove_last()
{
    if(isempty())
    {
        cout<<" THE ARRAY IS EMPTY AND CAN'T REMOVE ANY ITEMS BECAUSE :THE ARRAY 'S EMPTY  "<<endl;
    }
    else
    {
        length--;
    }
}
void Array::remove_position(int pos)
{
    if(isempty())
    {
        cout<<" THE ARRAY IS EMPTY AND CAN'T REMOVE ANY ITEMS BECAUSE :THE ARRAY 'S EMPTY  "<<endl;
    }
    else if(pos<0||pos>=sizee)
    {
        cout<<"ERROR : OUT OF RANGE "<<endl;
    }
    else
    {
        for(int i=pos; i<length; i++)
        {
            arr[i]=arr[i+1];
        }
        length--;
    }
}
void Array::ressize(int newsize)
{
    int *newarr=new int [newsize];
    for(int i=0; i<min(newsize,sizee); i++)
    {
        newarr[i]=arr[i];
    }
    delete[] arr;//reallocate memory (heap)
    arr=newarr;
    sizee=newsize;
}

Array::~Array()
{
    delete[] arr;
}
