/*2SUM problem
Another problem that can be solved using the two pointers method is the following
problem, also known as the 2SUM problem: given an array of n numbers and a
target sum x, find two array values such that their sum is x, or report that no
such values exist.*/


#include<bits/stdc++.h>
using namespace std;

void twoSumProblem(vector<int> v, int sum){
    sort(v.begin(),v.end());
    int lPointer=0, rPointer=v.size()-1;
    int destinedSum=v[lPointer]+v[rPointer];
    while(destinedSum!=sum){
        if(destinedSum<sum){
            lPointer++;
        }else if(destinedSum>sum){
            rPointer--;
        }
        destinedSum=v[lPointer]+v[rPointer];
    }
    cout<<v[lPointer]<<" "<<v[rPointer];
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