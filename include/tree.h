//Engineer : Ahmed Hazem

#ifndef TREE_H
#define TREE_H
#include<iostream>
using namespace std;

class tree
{
private:
    struct node
    {
        int item ;//store value
        node *left;
        node *right;
    };
    node *root;//first element on level zero
    int length;
    //can,t call these functions at the main function because ==> private
    int get_height_helper(node* temp);
    void pre_order(node *n);
    void in_order(node *n);
    void post_order(node *n);
    void delete_node( node *&nood);//delete (leaves node & node has 1 child & node has 2 child)


public:
    void print_pre_order();
    void print_in_order();
    void print_post_order();
    void insert_element(int element);
    bool search_element(int element);
    void remove_element(const int &element);//make pointer for the previous function(delete_node)
    void level_order();//print nodes  by levels
    int get_height();//calculate height of tree

    tree();
    ~tree();

};
#endif // TREE_H
