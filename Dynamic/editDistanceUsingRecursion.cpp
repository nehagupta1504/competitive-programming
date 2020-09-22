#include<bits/stdc++.h>
using namespace std;

int editDistance(string x, string y, int m, int n){
    if(m==0){
        return n;
    }
    if(n==0){
        return m;
    }
    if(x[m-1]==y[n-1]){
        return editDistance(x,y,m-1,n-1);
    }else{
       return 1+min(min(editDistance(x,y,m,n-1),editDistance(x,y,m-1,n)),editDistance(x,y, m-1,n-1));
    }
   
}

int main(){
    string x="LOVE";
    string y="MOVIE";
    cout<<editDistance(x, y, x.size(), y.size());
}