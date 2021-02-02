#include<bits/stdc++.h>
using namespace std;

struct subArray{
    int index1;
    int index2;
    int maxSum;
};



subArray MaximumSubarraySum(vector<int> A, int low, int high){
    subArray s;
    int sum = 0;
    int Max_sum = 0;
    s.index1 = low;
    for(int i=low; i <= high; i++){
        sum += A[i];
        if(sum >= 0 && sum > Max_sum){
            Max_sum = sum;
            s.index2 = i;
        }else if(sum < 0){
            sum = 0;
            s.index1 = i+1;
        }
    }
    s.maxSum = Max_sum;
    return s;
}

int main(){
    int n;
    cout<<"Enter Size of Array: \n";
    cin>>n;
    vector<int> A;
    for(int i=0; i<n ;i++){
        int temp;
        cin>>temp;
        A.push_back(temp);
    }
    subArray maxArray;
    maxArray = MaximumSubarraySum(A, 0, n-1);
    cout<<" Maximum subarray sum between "<<maxArray.index1+1<<" & "<<maxArray.index2+1<<" = "<<maxArray.maxSum;
}