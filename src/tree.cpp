//Engineer : Ahmed Hazem

#include "tree.h"
#include<queue>
#include<iostream>
using namespace std;
tree::tree()
{
    root = NULL;
    length = 0;
}
void  tree::print_pre_order()
{
    cout<<"PRE ORDER TRAVERSAL ==> ";
    pre_order(root);//root is first element
    cout<<endl;
}
//pre ==>( root left right )
void tree::pre_order(node *n)//give root to the function
{
    if(n!=NULL)
    {
        cout<<n->item<<" ";
        pre_order(n->left);//imp => leave this function when point to null
        pre_order(n->right);
    }
}
void  tree::print_in_order()
{
    cout<<"IN ORDER TRAVERSAL ==> ";
    in_order(root);
    cout<<endl;
}
//in ==>(left root right  )
void tree::in_order(node *n)//give root to the function
{
    if(n!=NULL)
    {
        in_order(n->left);   //print left
        cout<<n->item<<" ";  //print root
        in_order(n->right);  //print right
    }
}
void  tree::print_post_order()
{
    cout<<"POST ORDER TRAVERSAL ==> ";
    post_order(root);
    cout<<endl;
}
//post ==>( left right root)
void tree::post_order(node *n)//give root to the function
{
    if(n!=NULL)
    {
        post_order(n->left);  //print left
        post_order(n->right); //print right
        cout<<n->item<<" ";  //print root
    }
}
void tree::insert_element(int element)
{
    node *newnode=new node ;
    newnode->item=element;
    newnode->left=newnode->right=NULL;
    if(length==0)
    {
        root=newnode;
    }
    else
    {
        node *current=root;
        node *previous;
        while(current!=NULL)
        {
            previous=current;//previous late = 1

            if(element <= current->item)
            {
                current=current->left;
            }
            else
            {
                current=current->right;
            }
        }
        if(element <= previous->item)
        {
            previous->left=newnode;
        }
        else
        {
            previous->right=newnode;
        }
    }
    length++;
}
bool tree::search_element(int element)
{
    node *current=root;
    if(length==0)
    {
        cout<<"THE TREE IS EMPTY"<<endl;
    }
    else
    {
        while (current!=NULL)
        {
            if(element==current->item)
            {
                return true;
            }
            else if(element <= current->item)
            {
                current=current->left;
            }
            else
            {
                current=current->right;
            }
        }
        return false;//not founded
    }
}
void tree::delete_node(node * &nood)//delete (leaves node & nodes has 1 child & node has 2 child)
{
    if((nood->left==NULL)&&(nood->right==NULL))//delete leaves nodes
    {
        delete nood;//delete value from memo
        nood=NULL;//give null value ( make you avoid mistakes)
    }
    else if((nood->left!=NULL)&&(nood->right==NULL))//delete nodes which have one children(part 1)
    {
        node *current=nood;
        nood=nood->left;
        delete current;
    }
    else if((nood->left==NULL)&&(nood->right!=NULL))//delete nodes which have one children(part 2)
    {
        node *current=nood;
        nood=nood->right;
        delete current;
    }
    else //( (right & left) != null ) ==> nodes which have a 2 children
    {
        node *now=nood;
        node *current=nood->left;//want max value on the left road
        node *previous=NULL;//NULL ==> initial value
        while(current->right!=NULL)//current->right instead of previous pointer
        {
            previous=current;
            current=current->right;//to go to the max value at left road
        }
        now->item=current->item;//take value for del_node
        if(previous==NULL) // when the fist left node ==> is put for the del_node
        {
            previous=nood;
            previous->left=current->left;
            delete current;
        }
        else
        {
            previous->right=current->left;//current->left==>may be NULL or not
            delete current;//59
        }
    }
}
void tree::remove_element(const int &element)//root ==> (NULL || == || ????? )
{
    if(root==NULL)
    {
        cout<<"THE TREE IS EMPTY , CAN'T REMOVE ELEMENTS"<<endl;
    }
    else if(element==root->item)
    {
        delete_node(root);
    }
    else
    {
        node *current=root,*previous=root;
        if(element<=root->item)//go  on left road or right road
        {
            current=current->left;
        }
        else
        {
            current=current->right;
        }
        while(current!=NULL)//repeat more and more to ==>(current!=NULL || get element)
        {
            if(element==current->item)
            {
                break;//go out looooop
            }
            else
            {
                previous=current;//before current node
                if(element<=current->item)
                {
                    current=current->left;
                }
                else
                {
                    current=current->right;
                }
            }
        }
        if(current==NULL)//the element is not exist
        {
            cout<<"THE ELEMENT NOT FOUND"<<endl;
        }
        else if (element<=previous->item)
        {
            delete_node(previous->left);
        }
        else
        {
            delete_node(previous->right);
        }
    }
}
void tree::level_order()
{
    if(root==NULL)
    {
        return;
    }
    queue <node*> q;//don't forget #include<queue>
    q.push(root);//front==root
    cout<<"LEVEL ORDER FOR THE TREE ==> ";
    while(!q.empty())
    {
        node* current=q.front();
        q.pop();
        cout<<current->item<<" ";
        if(current->left!=NULL)
        {
            q.push(current->left);
        }
        if(current->right!=NULL)
        {
            q.push(current->right);
        }
    }
    cout<<endl;
}
int tree::get_height()
{
    cout<<"HEIGHT OF THE TREE ==> " ;
    if(root==NULL)
    {
        return -1;
    }
    else
    {
        return get_height_helper(root);
    }
}
int tree::get_height_helper(node* temp)
{
    if(temp==NULL)//empty sub tree
    {
        return-1;
    }
    int left_sub_tree = get_height_helper(temp->left);
    int right_sub_tree = get_height_helper(temp->right);
    return 1 + max(left_sub_tree,right_sub_tree);
}
tree::~tree()
{
}
