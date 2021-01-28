#include<bits/stdc++.h>
using namespace std;

void selectionSort(int A[], int n){
    for(int i=0; i<n-1; i++){
        int min = i;
        for(int j = i+1 ; j < n; j++){
           if(A[min]>A[j]){
               min = j;
           }
        }
        if(A[min] != A[i]){
            int temp = A[i];
            A[i] = A[min];
            A[min] = temp;
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
    selectionSort(a,  n);
    display(a, n);
}