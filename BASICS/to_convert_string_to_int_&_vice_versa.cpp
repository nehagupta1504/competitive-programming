#include<bits/stdc++.h>
using namespace std;

int main(){
   int tCases;
   cin>>tCases;
   while(tCases--){
       int number;
       cin>>number;
       string nString=to_string(number);
       reverse(nString.begin(),nString.end());
       stringstream geek(nString);
       number=0;
       geek >> number;
       cout<<number<<"\n";
   }
}