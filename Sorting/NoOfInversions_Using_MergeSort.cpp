#include<bits/stdc++.h>
using namespace std;

int merge(vector<int> &A, int p, int q, int r){
    int inversionCount = 0 ;
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
            inversionCount += n1-i ;
        }
    }
    return inversionCount;
}

int mergeSort(vector<int> &A, int p, int r){
    static int inversionCount = 0;
    if(p<r){
        int q = (p+r)/2;
        mergeSort(A, p, q);
        mergeSort(A, q+1, r);
       inversionCount += merge(A, p, q, r);
       //cout<<inversionCount<<" "<<p<<"\n"<<q<<"\n"<<r<<"\n";
       
    }
    return inversionCount;
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
    int inversionCount = 0 ;
    inversionCount = mergeSort(a,0,n-1);
    cout<<"No. of inversions="<< inversionCount<<"\n";
    display(a, n);
}