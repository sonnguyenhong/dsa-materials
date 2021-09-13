#include<bits/stdc++.h>
using namespace std;

typedef struct Node{
    int key;
    Node *left;
    Node *right;
    Node(int v){
        key = v;
        left = NULL;
        right = NULL;
    }
}Node;

Node *insert(Node *r, Node *p, int v)
{
    if(p == NULL)
        return r;
    if(p->left != NULL && p->right != NULL)
        return r;
    if(p->left == NULL){
        p->left = new Node(v);
    }else{
        p->right = new Node(v);
    }
    return r;
}

int height(Node *r, Node *p)
{
    if(p == NULL)
        return 0;
    int maxH = 0;
    int maxLeft = 0;
    int maxRight = 0;
    maxLeft = 1 + height(r, p->left);
    maxRight =  1 + height(r, p->right);
    maxH = maxLeft < maxRight ? maxRight : maxLeft;
}

Node *find(Node *r, int v)
{
    if(r == NULL)
        return NULL;
    if(r->key == v)
        return r;
    Node *t1 = find(r->left, v);
    Node *t2 = find(r->right, v);
    if(t1 == NULL && t2 == NULL)
        return NULL;
    else if(t1 == NULL)
        return t2;
    else return t1;
    return NULL;
}

int depth(Node *r, Node *p, int d)
{
    if(r == NULL)
        return -1;
    if(r == p)
        return d;
    int heightLeft = depth(r->left, p, d+1);
    int heightRight = depth(r->right, p, d+1);
    if(heightLeft > -1)
        return heightLeft;
    else if(heightRight > -1)
        return heightRight;
    return -1;
}

bool isLeaf(Node *r)
{
    return r->left == NULL && r->right == NULL;
}

int depthLeaves(Node *r, int d)
{
    if(r == NULL)
        return 100000;
    if(isLeaf(r))
        return d;
    int dleft = depthLeaves(r->left, d+1);
    int dright = depthLeaves(r->right, d+1);
    return dleft > dright ? dright : dleft;
}

Node *findMax(Node *r)
{
    if(r == NULL){
        Node *tmp = new Node(INT_MIN);
        return tmp;
    }
    Node *maxNode = r;
    Node *maxLeft = findMax(r->left);
    Node *maxRight = findMax(r->right);
    if(maxNode->key < maxLeft->key)
        maxNode = maxLeft;
    if(maxNode->key < maxRight->key)
        maxNode = maxRight;
    return maxNode;
}

Node *findMin(Node *r)
{
    if(r == NULL){
        Node *tmp = new Node(INT_MAX);
        return tmp;
    }
    Node *minNode = r;
    Node *minLeft = findMin(r->left);
    Node *minRight = findMin(r->right);

    if(minNode->key > minLeft->key)
        minNode = minLeft;
    if(minNode->key > minRight->key)
        minNode = minRight;
    return minNode;
}

int main()
{
    Node *r = new Node(10);
    r = insert(r, r, 4);
    r = insert(r, r, 7);
    Node *tmp = find(r, 4);
    r = insert(r, tmp, 5);
    r = insert(r, tmp, 8);
    cout<<depthLeaves(r, 1)<<endl;
    cout<<findMax(r)->key<<endl;
    cout<<findMin(r)->key<<endl;
}
