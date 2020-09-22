#include<bits/stdc++.h>
//for Taking input with less time
inline int getn(){
	int n=0, c=getchar_unlocked();
	while(c < '0' || c > '9') c = getchar_unlocked();
	while(c >= '0' && c <= '9')
		n = (n<<3) + (n<<1) + c - '0', c = getchar_unlocked();
	return n;
}

//print function can be used in place of cout
inline void print(int a)
{
	char snum[20];
	int i=0;
	do
	{
		snum[i++]=a%10+48;
		a=a/10;
	}while(a!=0);
	i=i-1;
	while(i>=0)
	pc(snum[i--]);
	pc('\n');
}

using namespace std;

int main(){
    //or we can use fro less complexity
    /*
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    */
    
    long long int testCases = getn();
    while(testCases--){
        int number = getn();
        int trailingZeroes=0;
        int specialcase=5;
        while(number/specialcase){
            trailingZeroes+=number/specialcase;
            specialcase*=5;
        }
        cout<<trailingZeroes<<"\n";
    }
}