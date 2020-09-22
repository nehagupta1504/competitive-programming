#include<bits/stdc++.h>
using namespace std;

int tree[100001];

void buildSegmentTree(vector<int> v,  int index, int startingIndex, int endingIndex){
    
    if(startingIndex == endingIndex){
        tree[index] = v[startingIndex];
        return;
    }
    
    int mid = (startingIndex + endingIndex)/2;
    buildSegmentTree(v, 2*index, startingIndex, mid );
    buildSegmentTree(v, 2*index+1, mid+1, endingIndex);
    
    tree[index] = min(tree[2*index], tree[2*index + 1]);
}

int querryMinimumRange(int index, int a, int b, int startingIndex, int endingIndex){
    if(endingIndex < a || startingIndex > b){
        return INT_MAX;
    }else if(endingIndex == startingIndex){
        return tree[index];
    }
    
    int mid = (startingIndex + endingIndex)/2;
    int x = querryMinimumRange(2*index, a, b, startingIndex, mid);
    int y = querryMinimumRange(2*index+1, a, b, mid+1, endingIndex);
    return min(x,y);
}

int main(){
    int n;
    cin>>n;
    vector<int> v;
    
    v.push_back(0);
    for(int i=1;i<=n;i++){
        int temp;
        cin>>temp;
        v.push_back(temp);
    }
    
    int index =1;
    buildSegmentTree(v, index, 1, n);
    
    int querries;
    cin>>querries;
    while(querries--){
        int a, b;
        cin>>a>>b;
        cout<<querryMinimumRange(1, a+1, b+1, 1, n)<<"\n";
    }
}