#include<bits/stdc++.h>
using namespace std;

int maxSpeed(int testCases) {
    while(testCases--) {
      int nCars;
      cin>>nCars;
      int maxSpeedCount=0;
      int currentMaxSpeed;
      for(int i=0;i<nCars;i++) {
            if(i==0){
                int ip;
                cin>>ip;
                maxSpeedCount++;
                currentMaxSpeed=ip;
            }else{
                int ip;
                cin>>ip;
                if(currentMaxSpeed>=ip){
                   maxSpeedCount++;
                   currentMaxSpeed=ip; 
                }
            }
        }
      cout<<maxSpeedCount<<"\n";
    }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int testCases;
  cin>>testCases;
  maxSpeed(testCases);
}