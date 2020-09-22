#include<bits/stdc++.h>
using namespace std;
void display(vector<int>v){
    for(int i=0;i<v.size();i++){
        cout<<v[i];
    }
    return;
}

void gp(vector<int> v,int index){
    //cout<<"in gp"<<"\n";
    if(index+1>=v.size()){
        display(v);
        cout<<"\n";
        return;
    }
    //cout<<"index="<<index<<"\n";
    for(int i=index;i<v.size();i++){
        swap(v[index],v[i]);
        //cout<<"index="<<index<<" "<<v[index]<<" "<<"i="<<" "<<v[i]<<"\n";
        gp(v,index+1);
    }
    return;
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