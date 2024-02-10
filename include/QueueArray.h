//Engineer : Ahmed Hazem
#ifndef QUEUEARRAY_H
#define QUEUEARRAY_H
class QueueArray
{ private:
    int *arr;//dynamic array to store elements
    int size;
    int length;//number of elements in array
    int front , rear;//points to (first & last) element

    public:
        bool isempty();
        bool isfull();
        void enqueue(const int &element);
        void dequeue();
        int getsize();
        int getfront();
        int getrear();
        void print();
        QueueArray(int size);//parameterized constructor
        ~QueueArray();
};

#endif // QUEUEARRAY_H
