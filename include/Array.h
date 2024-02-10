//Engineer : Ahmed Hazem

#ifndef ARRAY_H
#define ARRAY_H


class Array
{
private:
    int *arr;//for dynamic array
    int length;//number of element
    int sizee;//size of dynamic array

public:
    Array(int sizee);
    Array();
    ~Array();
    void insert_end(int element);
    void ressize(int newsize);
    void insert_positin(int pos, int element);
    void remove_last();
    void remove_position(int pos);
    bool isempty();
    int getsize();
    void print();
    bool is_full();


};

#endif // ARRAY_H
