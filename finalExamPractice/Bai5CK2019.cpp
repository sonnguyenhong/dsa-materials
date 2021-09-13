#include<bits/stdc++.h>
using namespace std;

typedef struct TNode{
    int key;
    TNode *left;
    TNode *right;
    TNode(int v){
        key = v;
        left = NULL;
        right = NULL;
    }
}TNode;

TNode *insert(TNode *head, int v)
{
    if(head == NULL)
        head = new TNode(v);
    else if(head->key > v)
        head->left = insert(head->left, v);
    else head->right = insert(head->right, v);
    return head;
}

void inOrder(TNode *head)
{
    if(head == NULL)
        return;
    inOrder(head->left);
    cout<<head->key<<" ";
    inOrder(head->right);
}

int count(TNode *r, int v)
{
    if(r == NULL)
        return 0;
    if(r->key < v){
        if(r->right->key > v)
            return 1 + count(r->right, v);
        else return count(r->right, v);
    }
    if(r->key > v)
        return 1 + count(r->left, v) + count(r->right, v);
    if(r->key == v)
        return count(r->right, v);
}

int main()
{
    TNode *head = new TNode(20);
    head = insert(head, 10);
    head = insert(head, 30);
    head = insert(head, 7);
    head = insert(head, 11);
    head = insert(head, 25);
    head = insert(head, 40);
    head = insert(head, 3);
    head = insert(head, 9);
    head = insert(head, 15);
    head = insert(head, 35);
    head = insert(head, 45);

    inOrder(head);
    cout<<endl;
    cout<<count(head, 13);
}
