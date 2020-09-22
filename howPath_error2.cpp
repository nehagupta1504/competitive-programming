/*Print all possible paths from top left to bottom right of a mXn matrix
The problem is to print all the possible paths from top left to bottom right of a mXn matrix with the constraints that from each cell you can either move only to right or down.
Examples :

Input : 1 2 3
        4 5 6
Output : 1 4 5 6
         1 2 5 6
         1 2 3 6

Input : 1 2 
        3 4
Output : 1 2 4
         1 3 4
????????????????link---->  https://www.geeksforgeeks.org/print-all-possible-paths-from-top-left-to-bottom-right-of-a-mxn-matrix/         
         */





#include<bits/stdc++.h>
using namespace std;

void pathFinding(int n,int m,int myMat[n][m], int rowm,int colm,vector<int> v){
    if(rowm+1==N&&colm+1==M){
        v.push_back(myMat[rowm][colm]);
        //cout<<"rowm="<<rowm<<" colm="<<colm<<" "<<myMat[rowm][colm]<<"\n";
        for(int i=0;i<v.size();i++){
            cout<<v[i];
        }
        cout<<endl;
        return;
    }
    v.push_back(*myMat[rowm][colm]);
    if(rowm+1<N){
        pathFinding(n,m,myMat,rowm+1,colm,v);
    }
    if(colm+1<M){
        pathFinding(n,m,myMat,rowm,colm+1,v);
    }
}


int main(){
    int n,int m;
    cin>>n>>m;
    int myMat[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>myMat[i][j];
        }
    }
    vector<int> v;
    pathFinding(n,m,myMat,0,0,v);
}