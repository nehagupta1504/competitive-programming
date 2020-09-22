//backtracking using NQueen's problem
// #define size 4
#define N 8 
#include<bits/stdc++.h>
using namespace std;


void display(int board[N][N], int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(board[i][j]==0){
                cout<<"_ ";
            }else{
                cout<<"Q ";
            }
        }
        cout<<"\n";
    }
}

bool isSafe(int board[N][N],int row,int col){
    
    //for checking in a column 
    for(int i=row;i>=0;i--){
        if(board[i][col]!=0)
        return false;
    }
    
    //for checking upper left diagonal & we're writing row-1& col-1 to not check again board[row][col] as we've already checked it
    for(int i=row-1,j=col-1;i>=0&&j>=0;i--,j--){
        if(board[i][j]!=0)
        return false;
    }
    
    //for checking upper right Diagonal & we're writing row-1& col+1 to not check again board[row][col] as we've already checked it
    for(int i=row-1,j=col+1;i>=0&&j<N;i--,j++){
        if(board[i][j]!=0)
        return false;
    }
    return true;
}


bool solveNQueen(int board[N][N],int row, int n){
    if(row==n){
        return true;
    }
    for(int i=0;i<n;i++){
        if(isSafe(board,row,i)==true){
            board[row][i]=1;
            if((solveNQueen(board,row+1,n))==true){
                return true;
            }
        }
        
        
        board[row][i]=0;
    }
    return false;
}

int main(){
  int board[N][N]={0};
  solveNQueen(board,0,N);
  display(board,N);
}