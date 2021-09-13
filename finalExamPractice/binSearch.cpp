#include<bits/stdc++.h>
using namespace std;

int solve(int a[], int l, int r, int v)
{
    if(l == r){
        if(a[l] == v)
            return l;
        else return -1;
    }else if(l < r){
        int m = (l+r)/2;
        if(a[m] == 0){
            if(a[m+1] == v)
                return m+1;
            else if(a[m-1] == v)
                return m-1;
            else if(a[m+1] > v)
                return solve(a, l, m-1, v);
            else if(a[m-1] < v)
                return solve(a, m+1, r, v);
        }

        else{
            if(a[m] == v)
                return m;
            else if(a[m] > v)
                return solve(a, l, m-1, v);
            else return solve(a, m+1, r, v);
        }
    }
    return -1;
}

int main()
{
    int a[14] = {0,2,3,4,5,0,7,8,9,10,0,13,16,0};
    cout<<solve(a, 0, 13, 2);
}
