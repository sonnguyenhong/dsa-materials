#include<bits/stdc++.h>
using namespace std;

void printArray(int a[], int n)
{
    for(int i = 0 ; i < n ; i++)
        cout<<a[i]<<" ";
    cout<<endl;
}

void insertionSort(int a[], int n)
{
    for(int i = 1 ; i < n ; i++){
        if(a[i] < a[i-1]){
            int tmp = a[i];
            int j = i - 1;
            while(j >= 0 && a[j] > tmp){
                a[j+1] = a[j];
                j--;
            }
            a[j+1] = tmp;
        }
    }
    //printArray(a, n);
}

void selectionSort(int a[], int n)
{
    for(int i = 0 ; i < n-1 ; i++){
        int imin = i;
        for(int j = i+1 ; j < n ; j++){
            if(a[j] < a[imin])
                imin = j;
        }
        swap(a[i], a[imin]);
    }
    //printArray(a, n);
}

void bubbleSort(int a[], int n)
{
    int swapped;
    do{
        swapped = 0;
        for(int i = 1 ; i < n ; i++){
            if(a[i] < a[i-1]){
                swap(a[i], a[i-1]);
                swapped = 1;
            }
        }
    }while(swapped == 1);
}

void merge(int a[], int l, int r, int m)
{
    int res[100];
    int k = 0;
    int i = l;
    int j = m+1;
    while(i <= m && j <= r){
        if(a[i] < a[j]){
            res[k] = a[i];
            k++;
            i++;
        }else{
            res[k] = a[j];
            k++;
            j++;
        }
    }
    while(i <= m){
        res[k] = a[i];
        i++;
        k++;
    }
    while(j <= r){
        res[k] = a[j];
        j++;
        k++;
    }

    int index = 0;
    for(int x = l ; x <= r ; x++){
        a[x] = res[index];
        index++;
    }
    delete[] res;
}

void mergeSort(int a[], int l, int r)
{
    if(l < r){
        int m = (l+r)/2;
        mergeSort(a, l, m);
        mergeSort(a, m+1, r);
        merge(a, l, r, m);
    }
}

//quickSort
int partition(int a[], int l, int r, int indexPivot)
{
    int pivot = a[indexPivot];
    swap(a[indexPivot], a[r]);
    int storeIndex = l;
    for(int i = l ; i < r ; i++){
        if(a[i] < pivot){
            swap(a[i], a[storeIndex]);
            storeIndex++;
        }
    }
    swap(a[storeIndex], a[r]);
    return storeIndex;
}

void quickSort(int a[], int l, int r)
{
    if(l < r){
        int index = (l+r)/2;
        index = partition(a, l, r, index);
        if(l < index)
            quickSort(a, l, index-1);
        if(index < r)
            quickSort(a, index+1, r);
    }
}


//heap sort
void heapify(int a[], int i, int n)
{

    int l = 2*i + 1;
    int r = 2*i + 2;

    int max = i;
    if(l < n && a[l] > a[max])
        max = l;
    if(r < n && a[r] > a[max])
        max = r;
    if(max != i){
        swap(a[i], a[max]);
        heapify(a, max, n);
    }
}

void buildHeap(int a[], int n)
{
    for(int i = n/2-1 ; i >= 0 ; i--){
        heapify(a, i, n);
    }
}

void heapSort(int a[], int n)
{
    buildHeap(a, n);
    for(int i = n-1 ; i >= 0 ; i--){
        swap(a[i], a[0]);
        heapify(a, 0, i);
    }
}

int main()
{
    int a[10] = {5, 1, 6, 7, 3, 2, 9, 10, 4, 8};
    //insertionSort(a, 10);
    //selectionSort(a, 10);
    //bubbleSort(a, 10);
    //mergeSort(a, 0, 9);
    //quickSort(a, 0, 9);
    heapSort(a, 10);

    printArray(a, 10);
}
