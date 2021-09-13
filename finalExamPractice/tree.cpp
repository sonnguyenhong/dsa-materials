#include<bits/stdc++.h>
using namespace std;

typedef struct Node{
    int id;
    Node *leftMostChild;
    Node *rightSibling;
    Node(int x){
        id = x;
        leftMostChild = NULL;
        rightSibling = NULL;
    }
}Node;

Node *root = NULL;

//Duyet thu tu truoc
void preOrder(Node *r)
{
    if(r == NULL)
        return;
    cout<<r->id<<" ";
    Node *p = r->leftMostChild;
    while(p != NULL){
        preOrder(p);
        p = p->rightSibling;
    }
}

//Duyet thu tu giua
void inOrder(Node *r)
{
    if(r == NULL)
        return;
    Node *t = r->leftMostChild;
    inOrder(t);
    cout<<r->id<<" ";
    if(t != NULL)
        t = t->rightSibling;
    while(t != NULL){
        inOrder(t);
        t = t->rightSibling;
    }
}

//Duyet thu tu sau
void postOrder(Node *r)
{
    if(r == NULL)
        return;
    Node *t = r->leftMostChild;
    while(t != NULL){
        postOrder(t);
        t = t->rightSibling;
    }
    cout<<r->id<<" ";
}

void insert(Node *r, Node *p, int id)
{

    if(p->leftMostChild == NULL){
        p->leftMostChild = new Node(id);
        return;
    }
    Node *tmp = p->leftMostChild;
    while(tmp->rightSibling != NULL)
        tmp = tmp->rightSibling;
    tmp->rightSibling = new Node(id);
}

Node *find(Node *r, int id)
{
    if(r == NULL)
        return NULL;
    if(r->id == id)
        return r;
    Node *tmp = r->leftMostChild;
    while(tmp != NULL){
        Node * h = find(tmp, id);
        if(h != NULL)
            return h;
        tmp = tmp->rightSibling;
    }
    return NULL;
}

int height(Node *r, Node *p)
{
    if(p == NULL)
        return 0;
    int maxH = 0;
    Node *t = p->leftMostChild;
    while(t != NULL){
        int h = height(r, t);
        if(h > maxH)
            maxH = h;
        t = t->rightSibling;
    }
    return maxH + 1;
}

int depth(Node *r, Node *p, int d)
{
    if(r == NULL)
        return -1;
    if(r == p)
        return d;
    Node *t = r->leftMostChild;
    while(t != NULL){
        if(t == p)
            return d+1;
        int dv = depth(t, p, d+1);
        if(dv > 0)
            return dv;
        t = t->rightSibling;
    }
    return -1;
}

int depth(Node *r, Node *p)
{
    return depth(r, p, 1);
}

Node *parent(Node *r, Node *p)
{
    if(r == NULL)
        return NULL;
    Node *t = r->leftMostChild;
    while(t != NULL){
        if(t == p)
            return r;
        Node *pt = parent(t, p);
        if(pt != NULL)
            return pt;
        t = t->rightSibling;
    }
}

int count(Node *r)
{
    if(r == NULL)
        return 0;
    int cnt = 1;
    Node *p = r->leftMostChild;
    while(p != NULL){
        cnt = cnt + count(p);
        p = p ->rightSibling;
    }
    return cnt;
}

int countLeaves(Node *r)
{
    if(r == NULL)
        return 0;
    int cnt = 0;
    Node *p = r->leftMostChild;
    if(p == NULL)
        cnt++;
    while(p != NULL){
        cnt = cnt + countLeaves(p);
        p = p->rightSibling;
    }
    return cnt;
}

int main()
{
    root = new Node(1);
    insert(root, root, 2);
    insert(root, root, 3);
    insert(root, root, 4);
    inOrder(root);
    cout<<endl;
    Node *tmp = find(root, 2);
    Node *pt = parent(root, tmp);
    cout<<countLeaves(root);
}
