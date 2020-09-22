//min heap using priority Queue;
/*the first element of the queue is the greatest of all elements in the queue and elements are in non increasing order(hence we can see that each element of the queue has a priority{fixed order}).*/

//Syntax priority_queue <int, vector<int>, greater<int>> g 

#include<bits/stdc++.h>
using namespace std;

void show(priority_queue<int, vector<int>, greater<int>>g){
    priority_queue<int, vector<int>, greater<int>> gq=g;
    
    while(!g.empty()){
        cout<<gq.top()<<" ";
        gq.pop();
    }
    cout<<"\n";
}


int main(){
    priority_queue<int, vector<int>, greater<int>> g;
    g.push(10);
    g.push(30);
    g.push(20);
    g.push(5);
    g.push(1);
    
    cout<<"printing all elements of min heap"<<"\n";
    show(g);
    cout<<"g.size()="<<g.size();
    cout<<"g.top()="<<g.top();
    
}