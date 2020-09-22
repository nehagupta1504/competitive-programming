#include<bits/stdc++.h>
using namespace std;

void subarraySum(vector<int> v, int sum){
    std::queue<int> q ;
    int lPointer, rPointer;
    lPointer=0;
    rPointer=0;
    int intermediateSum=v[lPointer];    //Entering first value in queue & then incrementing lPointer with 1;
    q.push(v[lPointer]);
    lPointer++;
    while(intermediateSum!=sum||lPointer!=v.size()){
        
        intermediateSum+=v[lPointer];
        q.push(v[lPointer]);
        while(intermediateSum>sum){
            q.pop();
            intermediateSum-=v[rPointer];
            rPointer++;
            
        }
        lPointer++;
    }
    if(q.empty()){
        cout<<"No subarray found!!";
    }
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
}

int main(){
    int n;
    cout<<"Enter size of array";
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        v.push_back(temp);
    }
    int sum;
    cout<<"Enter sum you want";
    cin>>sum;
    subarraySum(v, sum);
}