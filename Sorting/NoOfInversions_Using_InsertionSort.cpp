#include<bits/stdc++.h>
using namespace std;

int insertionSort(int A[], int n){
    int inversionCount = 0;
    for(int i=1;i<n ; i++){
        int key = A[i];
        int j = i-1;
        while(j >= 0 && A[j]>key){
            A[j+1] = A[j];
            j--;
            inversionCount++;
        }
        A[j+1] = key;
    }
    return inversionCount;
}

void display(int A[], int n){
    cout<<"Sorted Order \n";
    for(int i=0 ; i < n ;i++){
        cout<<A[i]<<" ";
    }
}

int main(){
    int n, inversionCount;
    cin>>n;
    int a[n];
    for(int i=0 ; i<n; i++){
        cin>>a[i];
    }
    inversionCount = insertionSort(a,  n);
    cout<<"No. Of Inversions = "<<inversionCount<<"\n";
    display(a, n);
}