/*A more difficult problem is the 3SUM problem that asks to find three array
values whose sum is x. Using the idea of the above algorithm, this problem can
be solved in O(n^2)*/


#include<bits/stdc++.h>
using namespace std;

void twoSumProblem(vector<int> v, int sum){
    set<pair<pair<int,int>,int>> s;
    sort(v.begin(),v.end());
    int onePointer=0, twoPointer=1, thirdPointer=v.size()-1;
    int destinedSum=0;
    for(int i=0;i<v.size()-2;i++){
        onePointer=i;
        twoPointer=i+1;
        thirdPointer=v.size()-1;
        destinedSum=v[onePointer]+v[twoPointer]+v[thirdPointer];
        //cout<<v[onePointer]<<" "<<v[twoPointer]<<" "<<v[thirdPointer]<<" "<<destinedSum<<"\n";
        for(int j=0;j<thirdPointer;j++){
            if(destinedSum>sum){
                thirdPointer--;
            }else if(destinedSum<sum){
                twoPointer++;
            }else if(destinedSum==sum){
                pair<pair<int,int>,int> x=make_pair(make_pair(v[onePointer],v[twoPointer]),v[thirdPointer]);
                s.insert(x);
                // cout<<v[onePointer]<<" "<<v[twoPointer]<<" "<<v[thirdPointer]<<"\n";
                twoPointer++;
            }
            destinedSum=v[onePointer]+v[twoPointer]+v[thirdPointer];
        }
    }
      for (auto const &x : s) { 
        cout << x.first.first << ", "
             << x.first.second << ","<<x.second<<"\n";
    } 
}

int main(){
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        v.push_back(temp);
    }
    
    int sum;
    cin>>sum;
    twoSumProblem(v,sum);
}