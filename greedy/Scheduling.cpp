#include<bits/stdc++.h>
using namespace std;



int main(){
    int n;
    cin>>n;
    map<int,int> jobs;
    vector<int> copy;
    for(int i=0;i<n;i++){
        int start, end;
        cin>>start>>end;
        jobs.insert(pair<int,int>(end,start));
        copy.push_back(end);
        
    }
    sort(copy.begin(),copy.end());
    int count=0;
    cout<<count<<" ";
    count++;
    int lastjob=copy[0];
    //Scheduling algorithm
    for(int i=0;i<copy.size()-1;i++,count++){
        //cout<<"hiiii!!!"<<" \n";
        //cout<<" \n"<<lastjob<<" "<<jobs[copy[i+1]]<<"\n";
        if(lastjob<=jobs[copy[i+1]]){
            cout<<count<<" ";
            lastjob=copy[i+1];
            //cout<<"m here"<<"\n";
        }
    }
}