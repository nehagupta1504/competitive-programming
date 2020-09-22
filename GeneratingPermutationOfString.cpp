#include<bits/stdc++.h>
using namespace std;

void permute(string str, string output){ 
    if(str.size()==0){
        cout<<output<<"\n";
        return;
    }
    for(int i=0;i<str.size();i++){
        //substr(initial,end) is a substring function to get substring here it'll will give substring from 1 to end of string ex- ABC substr(1) will result in BC
        permute(str.substr(1),output+str[0]);
        //rotate is a predefined function()
        rotate(str.begin(),str.begin()+1,str.end());
    }
}

int main(){
    string s;
    cin>>s;
    permute(s,"");
}