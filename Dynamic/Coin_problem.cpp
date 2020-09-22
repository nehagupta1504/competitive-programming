#include<bits/stdc++.h>
using namespace std;

void countCoin(vector<int>v, int sum, int count,vector<int> &result){
    if(sum==0){
        result.push_back(count);
        count=0;
        return;
    }
    
    for(int i=v.size()-1;i>=0;i--){
        cout<<sum<<" "<<v[i]<<" "<<count<<"\n";
        if(sum>=v[i]){
            int mod=sum/v[i];
            countCoin(v, sum-(mod*v[i]), count+mod, result);
        }
    }
}

int main(){
    int n;
    cout<<"Enter no. of coins"<<"\n";
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        v.push_back(temp);
    }
    
    sort(v.begin(),v.end());
    int sum;
    cout<<"Enter the sum you want"<<"\n";
    cin>>sum;
    vector<int> result;
    countCoin(v,sum,0,result);
    sort(result.begin(),result.end());
    cout<<"\n\n\n"<<result[0];
}