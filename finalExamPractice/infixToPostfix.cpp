#include<bits/stdc++.h>
using namespace std;

int prec(char c)
{
    if(c == '^')
        return 3;
    if(c == '*' || c == '/')
        return 2;
    if(c == '+' || c == '-')
        return 1;
    return -1;
}

bool isOperand(char c)
{
    if(c >= 48 && c <= 57)
        return true;
    if(c >= 97 && c <= 122)
        return true;
    return false;
}

bool isOperator(char c)
{
    if(c == '^' || c == '*' || c == '/' || c == '+' || c == '-')
        return true;
    return false;
}

void process(string ex)
{
    stack<char> s;
    s.push('N');
    string res = "";
    int l = ex.length();
    for(int i = 0 ; i < l ; i++){
        if(isOperand(ex[i]))
            res = res + ex[i];
        else if(isOperator(ex[i])){
            if(prec(s.top()) <= prec(ex[i]))
                s.push(ex[i]);
            else{
                while(prec(s.top()) >= prec(ex[i])){
                    char c = s.top();
                    res = res + c;
                    s.pop();
                }
            }
        }
        if(ex[i] == '(')
            s.push(ex[i]);
        if(ex[i] == ')'){
            while(s.top() != '('){
                char c = s.top();
                res = res + c;
                s.pop();
            }
            s.pop();
        }
    }
    while(s.top() != 'N'){
        char c = s.top();
        res = res + c;
        s.pop();
    }

    //print Postfix Expression
    cout<<res<<endl;
}

int main()
{
    string ex = "(5-x/y)*(a+7)";
    process(ex);
}
