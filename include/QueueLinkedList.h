//Engineer : Ahmed Hazem

#ifndef QUEUELINKEDLIST_H
#define QUEUELINKEDLIST_H
class QueueLinkedList
{
private:
    struct node
    {
        int item;
        node *next;
    };
    node*front,*rear;
    int length;//number of elements

public:
    bool isempty();
    void enqueue(const int &element);
    void dequeue();//deallocate first element (remove left)
    int getsize();
    int getfront();
    int getrear();
    void print();
    void clear();
    QueueLinkedList();
    ~QueueLinkedList();
};

#endif // QUEUELINKEDLIST_H
