#include<bits/stdc++.h>
using namespace std;

void bubbleSort(int A[], int n){
    for(int i=0; i<n-1; i++){
       for(int j = 0 ; j < n-i-1 ; j++){
           if(A[j] > A[j+1]){
               int temp = A[j];
               A[j] = A[j+1];
               A[j+1] = temp;
           }
       }
    }
}

void display(int A[], int n){
    cout<<"Sorted Order \n";
    for(int i=0 ; i < n ;i++){
        cout<<A[i]<<" ";
    }
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0 ; i<n; i++){
        cin>>a[i];
    }
    bubbleSort(a,  n);
    display(a, n);
}