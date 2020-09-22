#include<bits/stdc++.h>
using namespace std;
#define N 5
#define M 5

int findPath(int arr[][N]){
   int dp[N][M];
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(i==0){
                if(j==0){
                    dp[i][j]=arr[i][j];
                }else{
                    dp[i][j]=dp[i][j-1]+arr[i][j];
                }
            }else{
                if(j==0){
                    dp[i][j]=dp[i-1][j]+arr[i][j];
                }else{
                    dp[i][j]=max(dp[i][j-1],dp[i-1][j])+arr[i][j];
                    
                }
            }
        }
        cout<<"\n";
    }
    return dp[N-1][M-1];
}

int main(){
    int arr[][M]={{3,7,9,2,7},{9,8,3,5,5},{1,7,9,8,5},{3,8,6,4,10},{6,3,9,7,8}};
    
    cout<<findPath(arr);
}