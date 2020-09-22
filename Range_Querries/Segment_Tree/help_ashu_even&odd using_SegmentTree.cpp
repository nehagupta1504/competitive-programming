#include<bits/stdc++.h>
using namespace std;

const int maxN=100001;
pair<int, int> tree[4*maxN];

void build(vector<int> v, int index, int startingindex, int endingIndex){
    if(startingindex == endingIndex){
        if(v[startingindex]%2 == 0){
            //even
            tree[index] = {1,0};
            //cout<<index<<" "<<tree[index].first<<" "<<tree[index].second<<"\n";
            return;
        }else{
            tree[index] = {0,1};
            //cout<<index<<" "<<tree[index].first<<" "<<tree[index].second<<"\n";
            return;
        }
    }
    
    int mid = (startingindex + endingIndex)/2;
    build(v, 2*index, startingindex, mid);
    build(v, 2*index+1, mid+1, endingIndex);
    
    tree[index].first = tree[2*index].first + tree[2*index + 1].first;
    tree[index].second = tree[2*index].second + tree[2*index + 1].second;
    //cout<<index<<" "<<tree[index].first<<" "<<tree[index].second<<"\n";
}

void update(vector<int> v, int a, int b, int index, int startingindex, int endingIndex){
    // here a is the update index & b is value to be updated
    if(startingindex>a || endingIndex<a){
        return ;
    }else if(startingindex == endingIndex && startingindex == a){
        if(v[a]%2 == 0){
            //even
            tree[index]={1,0};
            return;
        }else{
            //odd
            tree[index]={0,1};
            return;
        }
    }
    
    int mid = (startingindex + endingIndex)/2;
    update(v, a, b, 2*index, startingindex, mid);
    update(v, a, b, 2*index+1, mid+1, endingIndex);
    
    tree[index].first = tree[2*index].first + tree[2*index + 1].first;
    tree[index].second = tree[2*index].second + tree[2*index + 1].second;
}

int getEven(int a, int b, int index, int startingindex, int endingIndex){
    if(startingindex>b || endingIndex < a){
        return 0;
    }else if(startingindex == endingIndex){
        //cout<<index<<" "<<tree[index].first<<" "<<tree[index].second<<"\n";
        return tree[index].first;
    }
    
    int mid = (startingindex + endingIndex)/2;
    int left = getEven(a, b, 2*index, startingindex, mid);
    int right = getEven(a, b, 2*index+1, mid+1, endingIndex);
    //cout<<left<<" "<<right<<"\n";
    return left + right ;
}

int getOdd(int a, int b, int index, int startingindex, int endingIndex){
    if(startingindex>b || endingIndex < a){
        return 0;
    }else if(startingindex == endingIndex){
        return tree[index].second;
    }
    
    int mid = (startingindex + endingIndex)/2;
    int left = getOdd(a, b, 2*index, startingindex, mid);
    int right = getOdd(a, b, 2*index+1, mid+1, endingIndex);
    
    return left + right ;
}

int main(){
    vector<int> v;
    int n;
    cin>>n;
    v.push_back(0);
    for(int i=1;i<=n;i++){
        int temp;
        cin>>temp;
        v.push_back(temp);
    }
    
    build(v, 1, 1, n);
    int querries;
    cin>>querries;
    while(querries--){
        int choice, a, b;
        cin>>choice>>a>>b;
        switch(choice){
            case 0: v[a]=b;
                    update(v, a, b, 1, 1, n);
                    break;
            case 1: cout<<getEven(a, b, 1, 1,n)<<"\n";
                    break;
            case 2: cout<<getOdd(a, b, 1, 1, n)<<"\n";
                    break;
        }
    }
}
