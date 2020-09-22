#include<bits/stdc++.h>
using namespace std;

void slidingWindow(vector<int> v, int wSize){
    for(int i=0;i<v.size()-wSize+1;i++){
        vector<int> window;
        for(int j=0;j<wSize;j++){
            window.push_back(v[i+j]);
        }
        make_heap(window.begin(), window.end());
        cout<<window.front()<<" ";
    }
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
    int wSize;
    cin>>wSize;
    slidingWindow(v,wSize);
}