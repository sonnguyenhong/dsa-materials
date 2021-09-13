#include<bits/stdc++.h>
using namespace std;

typedef struct Node{
    char c;
    Node *next;
    Node(char v){
        c = v;
        next = NULL;
    }
}Node;

typedef struct Stack{
    Node *top;
    Stack(){
        top = NULL;
    }

    Node *push(char x){
        Node *tmp = new Node(x);
        tmp->next = top;
        top = tmp;
        return top;
    }

    void pop(){
        Node *tmp = top;
        top = top->next;
        delete tmp;
    }

    char topElement(){
        return top->c;
    }

    bool isEmpty(){
        return top == NULL;
    }
}Stack;

bool isMatch(char a, char b)
{
    if(a == '(' && b == ')')
        return true;
    if(a == '[' && b == ']')
        return true;
    if(a == '{' && b == '}')
        return true;
    return false;
}

bool solve(string s)
{
    Stack *st = new Stack();
    int l = s.length();
    for(int i = 0 ; i < l ; i++){
        if(s[i] == '(' || s[i] == '{' || s[i] == '[')
            st->push(s[i]);
        if(s[i] == ')' || s[i] == '}' || s[i] == ']'){
            if(!isMatch(st->topElement(), s[i]))
                return false;
            st->pop();
        }
    }
    if(st->isEmpty())
        return true;
    return false;
}

int main()
{
    string s = "{}[]()((()))";
    cout<<solve(s);
}
