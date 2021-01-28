#include<bits/stdc++.h>
using namespace std;

//Adjacency list representation

void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
}

void printAdjList(vector<int> adj[], int N){
    for(int i=0; i < N; i++){
        cout<<i;
        for(auto x: adj[i]){
            cout<<"->"<<x;
        }
        cout<<"\n";
    }
}

int main(){
    int N = 4; //let's take it a rectangle 0->1->2->3 $ 4 is connected to 1 3->1
    vector<int> adj[N];
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 1);
    printAdjList(adj, N);
}