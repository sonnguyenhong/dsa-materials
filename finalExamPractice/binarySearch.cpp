#include<bits/stdc++.h>
using namespace std;

bool bSearch(int a[], int l, int r, int v)
{
    if(l == r){
        if(a[l] == v)
            return true;
        return false;
    }
    if(l<r){
        int m = (l+r)/2;
        if(a[m] == v)
            return true;
        else if(a[m] < v){
            return bSearch(a, m+1, r, v);
        }else return bSearch(a, l, m-1, v);
    }
    return false;
}

int solve(int a[], int n, int b)
{
    int cnt = 0;
    for(int i = 0 ; i < n-1 ; i++){
        int v = b - a[i];
        if(bSearch(a, i+1, n-1, v))
            cnt++;
    }
    return cnt;
}

int main()
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout<<solve(a, 10, 7)<<endl;
}
