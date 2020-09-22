#include<bits/stdc++.h>;
using namespace std;

/*
            prefix sum array can be constructed in O(n) time.
            For example, consider the following array:
    value-    1 3 4 8 6 1 4 2
    index-    0 1 2 3 4 5 6 7
            The corresponding prefix sum array is as follows:
    prefixSum-1 4 8 16 22 23 27 29
*/

void prefixSum(vector<int> &v){
    for(int i=1;i<v.size();i++){
        v[i]+=v[i-1];
    }
}

/*
	    we r not using simple for loop to calculate the sum as there can be 
	    multiple test cases & thus it'll take O(tn) time but is t & n are large
	    it will result  in much more complexity thus using prefix sum we can cal-
	    -culate prefix sum in O(n) time once & all testcases now can be solved in 
	    O(1) time thus taking overall of O(n) time.
*/

void sumRangeQuerry(vector<int> v, int index1, int index2){
    prefixSum(v);
    cout<<"Sum of values b/w index "<<index1<<" & "<<index2<<" "<<v[index2]-v[index1-1];
}

int main(){
    vector<int>v;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        v.push_back(temp);
    }
    int index1, index2;
    cout<<"Enter the indexes you want the sum of"<<"\n";
    cin>>index1>>index2;
    sumRangeQuerry(v, index1, index2);
}