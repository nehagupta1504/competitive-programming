#include<bits/stdc++.h>
using namespace std;
void display(vector<int>v){
    for(int i=0;i<v.size();i++){
        cout<<v[i];
    }
    return;
}

void gp(vector<int> v,int index){
    //sorting the vector
    sort(v.begin(),v.end());
    cout<<"Possible permutations are:";
    do{
        display(v);
        cout<<"\n";
    }while(next_permutation(v.begin(),v.end()));
}

int main(){
    vector<int> v;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        v.push_back(temp);
    }
    //cout<<"in main"<<"\n";
    int index=0;
    gp(v,index);
}