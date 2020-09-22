#include<bits/stdc++.h>
using namespace std;

int editDistance(string x, string y){
    int a=x.size();
    int b=y.size();
    cout<<a<<" "<<b<<"\n";
    int dp[2][b+1];
    for(int i=0;i<=a;i++){
        for(int j=0;j<=b;j++){
            if(i==0){
                dp[i%2][j]=j;
            }else if(j==0){
                dp[i%2][j]=i;
            }else if(x[i-1]==y[j-1]){
                dp[i%2][j]=dp[(i-1)%2][j-1];
            }else{
                dp[i%2][j]=min(min(dp[(i-1)%2][j]+1,dp[i%2][j-1]+1),dp[(i-1)%2][j-1]+1);
            }
            cout<<dp[i%2][j]<<"  ";
        }
        cout<<"\n";
    }
    return dp[a%2][b];
}

int main(){
    string x="LOVE";
    string y="MOVIE";
    cout<<editDistance(x,y);
}