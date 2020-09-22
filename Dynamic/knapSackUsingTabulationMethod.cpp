#include<bits/stdc++.h>
using namespace std;

int knapSack(vector<int> profit, vector<int>weight, int massOfBag){
    int noOfItems = profit.size();
    int currentMass = massOfBag;
    int dp[noOfItems+1][currentMass+1];
    for(int i=0;i<=noOfItems;i++){
        for(int j=0;j<=currentMass;j++){
            if(i==0||j==0){
                dp[i][j]=0;
            }else{
                    dp[i][j]=max(dp[i-1][j],dp[i-1][j-weight[i-1]]+profit[i-1]);
                
            }
            cout<<dp[i][j]<<"  ";
        }
        cout<<"\n";
    }
    return dp[noOfItems][currentMass];
}

int main(){
    vector<int> profit;
    vector<int> weight;
    int noOfItems;
    cin>>noOfItems;
    for(int i=0;i<noOfItems;i++){
        int temp;
        cin>>temp;
        profit.push_back(temp);
        cin>>temp;
        weight.push_back(temp);
    }
    
    int massOfBag;
    cin>>massOfBag;
    cout<<knapSack(profit,weight,massOfBag);
}