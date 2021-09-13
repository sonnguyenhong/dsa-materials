#include<bits/stdc++.h>
using namespace std;

typedef struct Node{
    int id;
    Node *left;
    Node *right;
}Node;

Node *makeNode(int v)
{
    Node *p = new Node();
    p->id = v;
    p->left = NULL;
    p->right = NULL;
    return p;
}

Node *insert(Node *r, int v)
{
    if(r == NULL)
        r = makeNode(v);
    else if(v >= r->id)
        r->right = insert(r->right, v);
    else r->left = insert(r->left, v);
    return r;
}

Node *search(Node *r, int v)
{
    if(r == NULL)
        return NULL;
    if(r->id == v)
        return r;
    if(r->id < v)
        return search(r->right, v);
    else return search(r->left, v);
}

Node *findMin(Node *r)
{
    Node *p = r;
    if(r == NULL)
        return NULL;
    while(p->left != NULL)
        p = p->left;
    return p;
}

Node *del(Node *r, int v)
{
    if(r == NULL)
        return NULL;
    if(r->id > v)
        r->left = del(r->left, v);
    else if(r->id < v)
        r->right = del(r->right, v);
    else{
        if(r->left != NULL && r->right != NULL){
            Node *tmp = findMin(r->right);
            r->id = tmp->id;
            r->right = del(r->right, tmp->id);
        }else{
            Node *tmp = r;
            if(r->left == NULL)
                r = r->right;
            else r = r->left;
            delete tmp;
        }
    }
    return r;
}

void inOrder(Node *r)
{
    if(r == NULL)
        return;
    inOrder(r->left);
    cout<<r->id<<" ";
    inOrder(r->right);
}

int main()
{
    Node *root = makeNode(10);
    root = insert(root, 6);
    root = insert(root, 20);
    root = insert(root, 4);
    root = insert(root, 8);
    root = insert(root, 15);
    root = insert(root, 29);
    root = insert(root, 7);
    root = insert(root, 9);
    cout<<"Before delete: ";
    inOrder(root);
    cout<<endl;
    root = del(root, 6);
    cout<<"After delete: ";
    inOrder(root);
}
