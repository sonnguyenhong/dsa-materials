#include<bits/stdc++.h>
using namespace std;

typedef struct Node{
    int id;
    Node *left;
    Node *right;
    Node(int v){
        id = v;
        left = NULL;
        right = NULL;
    }
}Node;

void inOrder(Node *r)
{
    if(r == NULL)
        return;
    inOrder(r->left);
    cout<<r->id<<" ";
    inOrder(r->right);
}

void preOrder(Node *r)
{
    if(r == NULL)
        return;
    cout<<r->id<<" ";
    preOrder(r->left);
    preOrder(r->right);
}

void postOrder(Node *r)
{
    if(r == NULL)
        return;
    postOrder(r->left);
    postOrder(r->right);
    cout<<r->id<<" ";
}

void insert(Node *r, Node *p, int id)
{
    if(p->left != NULL && p->right != NULL)
        return;
    if(p->left == NULL){
        p->left = new Node(id);
        return;
    }
    else{
        p->right = new Node(id);
        return;
    }
}

Node *find(Node *r, int id)
{
    if(r == NULL)
        return NULL;
    if(r->id == id)
        return r;
    Node *hl = find(r->left, id);
    Node *hr = find(r->right, id);
    if(hl == NULL && hr == NULL)
        return NULL;
    if(hl != NULL)
        return hl;
    else return hr;
}

int height(Node *r, Node *p)
{
    if(p == NULL)
        return 0;
    int maxH = 0;
    int maxLeft = 0;
    int maxRight = 0;
    maxLeft = 1 + height(r, p->left);
    maxRight = 1 + height(r, p->right);
    maxH = maxLeft > maxRight ? maxLeft : maxRight;
    return maxH;
}

int depth(Node *r, Node *p, int d)
{
    if(r == NULL)
        return -1;
    if(r == p)
        return d;
    int depthLeft = depth(r->left, p, d+1);
    int depthRight = depth(r->right, p, d+1);
    return depthLeft > depthRight ? depthLeft : depthRight;
}

int depth(Node *r, Node *p)
{
    return depth(r, p, 1);
}

Node *parent(Node *r, Node *p)
{
    if(r == NULL)
        return NULL;
    if(r->left == p || r->right == p)
        return r;
    Node *lp = parent(r->left, p);
    Node *rp = parent(r->right, p);
    if(lp == NULL && rp == NULL)
        return NULL;
    if(lp == NULL)
        return rp;
    if(rp == NULL)
        return lp;
    return NULL;
}

int count(Node *r)
{
    if(r == NULL)
        return 0;
    return 1 + count(r->left) + count(r->right);
}

int countLeaves(Node *r)
{
    if(r == NULL)
        return 0;
    if(r->left == NULL && r->right == NULL)
        return 1;
    return countLeaves(r->left) + countLeaves(r->right);
}

int main()
{
    Node *r = new Node(1);
    insert(r, r, 2);
    insert(r, r, 3);
    Node *tmp = find(r, 2);
    insert(r, tmp, 4);
    insert(r, tmp, 5);
    tmp = find(r, 3);
    insert(r, tmp, 6);
    insert(r, tmp, 7);

    inOrder(r);
    cout<<endl;
    cout<<parent(r, tmp)->id<<endl;
    cout<<count(r)<<endl;
    cout<<countLeaves(r)<<endl;
}
