/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x = 5;
    for (int i = 31; i >= 0; i--) {
        if (x&(1<<i)) cout << "1";
        else cout << "0";
    }

    return 0;
}
