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

Node *search(Node *r, int v)
{
    if(r == NULL)
        return NULL;
    if(r->key == v)
        return r;
    Node *rleft = search(r->left, v);
    Node *rright = search(r->right, v);
    if(rleft != NULL)
        return rleft;
    if(rright != NULL)
        return rright;
    return NULL;
}

Node *insert(Node *r, Node *p, int v)
{
    Node *tmp = new Node(v);
    if(r == NULL)
        return tmp;
    if(p == NULL)
        return r;
    if(p->left == NULL)
        p->left = tmp;
    else if(p->right == NULL)
        p->right = tmp;
    return r;
}

void inOrder(Node *r)
{
    if(r == NULL)
        return;
    inOrder(r->left);
    cout<<r->key<<" ";
    inOrder(r->right);
}

bool checkMinHeap(Node *r)
{
    if(r == NULL)
        return true;
    if(r->left == NULL && r->right == NULL)
        return true;
    if(r->left->key < r->key || r->right->key < r->key)
        return false;
    bool checkLeft = checkMinHeap(r->left);
    bool checkRight = checkMinHeap(r->right);
    return checkLeft && checkRight;
}

int count2(Node *r)
{
    if(r == NULL)
        return 0;
    if(r->left != NULL && r->right != NULL)
        return 1 + count2(r->left) + count2(r->right);
    else if(r->left != NULL)
        return count2(r->left);
    else    return count2(r->right);
}

bool checkBST(Node *r)
{
    if(r == NULL)
        return true;
    if(r->left == NULL && r->right == NULL)
        return true;
    else if(r->left != NULL){
        if(r->left->key >= r->key)
            return false;
    }else if(r->right != NULL){
        if(r->right->key < r->key)
            return false;
    }
    else if(r->left->key >= r->key || r->right->key < r->key)
        return false;
    bool checkLeft = checkBST(r->left);
    bool checkRight = checkBST(r->right);
    return checkLeft && checkRight;
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

bool checkAVL(Node *r)
{
    if(!checkBST(r)){
        return false;
    }else{
        if(r == NULL)
            return true;
        if(abs(height(r, r->left) - height(r, r->right)) > 1)
            return false;
        bool checkLeft = checkAVL(r->left);
        bool checkRight = checkAVL(r->right);
        return checkLeft && checkRight;
    }
}

int main()
{
    Node *r = new Node(10);
    r = insert(r, r, 5);
    r = insert(r, r, 15);
    Node *tmp = search(r, 5);
    r = insert(r, tmp, 3);
    r = insert(r, tmp, 7);
    tmp = search(r, 15);
    r = insert(r, tmp, 13);
    r = insert(r, tmp, 22);
    tmp = search(r, 3);
    r = insert(r, tmp, 2);
    tmp = search(r, 2);
    r = insert(r, tmp, 1);

    //cout<<tmp->key;
    inOrder(r);
    cout<<endl;
    cout<<"is Min Heap: "<<checkMinHeap(r)<<endl;
    cout<<"count 2: "<<count2(r)<<endl;
    cout<<"check BST: "<<checkBST(r)<<endl;
    cout<<"check AVL: "<<checkAVL(r)<<endl;
}
