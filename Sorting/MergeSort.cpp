#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &A, int p, int q, int r){
    int n1 = q-p+1;
    int n2 = r-q;
    int L[n1+1], R[n2+1];
    L[n1] = INT_MAX;
    R[n2] = INT_MAX;
    for(int i = 0 ; i < n1; i++){
        L[i] = A[p+i];
    }
    for(int i = 0 ; i < n2; i++){
        R[i] = A[q+i+1];
    }
    int i = 0, j = 0;
    for(int k = p ; k <= r ;  k++){
        if(L[i] <= R[j]){
            A[k] = L[i];
            i++;
        }else{
            A[k] = R[j];
            j++;
        }
    }
}

void mergeSort(vector<int> &A, int p, int r){
    if(p<r){
        int q = (p+r)/2;
        mergeSort(A, p, q);
        mergeSort(A, q+1, r);
        merge(A, p, q, r);
    }
}



void display(vector<int> A, int n){
    cout<<"Sorted Order \n";
    for(int i=0 ; i < n ;i++){
        cout<<A[i]<<" ";
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> a;
    for(int i=0 ; i<n; i++){
        int temp;
        cin>>temp;
        a.push_back(temp);
    }
    //display(a, n);
    mergeSort(a,0,n-1);
    display(a, n);
}