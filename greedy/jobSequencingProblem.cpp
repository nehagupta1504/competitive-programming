#include<bits/stdc++.h>
using namespace std;

class job{
    public:
     string id;
     int deadline;
     int profit;
};

bool comparison(job a,job b){
    return a.profit>b.profit;
}
int main(){
    int n=4;
    int result[n]={0};
    vector<string> values;
    job j[]={{"a",4,20},{"b",1,10},{"c",1,40},{"d",1,30}};
    sort(j,j+n,comparison);
    
    for(int i=0;i<n;i++){
        cout<<j[i].profit<<"\n";
        int re=j[i].deadline;
        while(re>0){
            re--;
            if(result[re]==0){
            result[re]=j[i].profit;
            values.push_back(j[i].id);
            cout<<j[i].id;
            cout<<result[j[i].deadline]<<"\n";
            break;
            }
        }
       
    }
    for(auto i=values.begin();i!=values.end();i++){
        cout<<*i<<" ";
    }
}