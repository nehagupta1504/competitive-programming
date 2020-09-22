#include<bits/stdc++.h>
#define ll long long
#define nl "\n"
//Take input with less time complexity
inline int getn(){
	int n=0, c=getchar_unlocked();
	while(c < '0' || c > '9') c = getchar_unlocked();
	while(c >= '0' && c <= '9')
		n = (n<<3) + (n<<1) + c - '0', c = getchar_unlocked();
	return n;
}
using namespace std;

int maxSpeed(int testCases) {
    while(testCases--) {
      int nCars=getn();
      int maxSpeedCount=0;
      int currentMaxSpeed;
      for(int i=0;i<nCars;i++) {
            if(i==0){
                int ip=getn();
                maxSpeedCount++;
                currentMaxSpeed=ip;
            }else{
                int ip=getn();
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
  int testCases=getn();
  maxSpeed(testCases);
}