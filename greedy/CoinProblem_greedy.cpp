#include<bits/stdc++.h>
using namespace std;

int countCoin(vector<int>v, int size,int sum){
    int count=0,Equalsum=sum;
    for(int i=v.size()-1;i>=0;i--){
        if(Equalsum>=v[i]){
            int mod=Equalsum/v[i];
            Equalsum=Equalsum-(mod*v[i]);
            count+=mod;
        }
        if(sum==0){
            break;
        }
    }
    return count;
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
    cout<<countCoin(v,n,sum);
}