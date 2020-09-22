#include<bits/stdc++.h>
using namespace std;

int knapSack(vector<int> profit, vector<int>weight, int remMass, int currentProfit, int index){
    static int maxProfit=0;
    if(remMass==0){
        if(maxProfit<currentProfit){
            maxProfit=currentProfit;
        }
    }
    if(weight[index]<=remMass&&index>=0){
        knapSack(profit, weight, remMass-weight[index], currentProfit+profit[index], index-1);
        
    }
    if(index>=0){
        knapSack(profit, weight, remMass, currentProfit, index-1);
    }
    return maxProfit;
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
    cout<<knapSack(profit,weight,massOfBag,0,noOfItems-1);
}