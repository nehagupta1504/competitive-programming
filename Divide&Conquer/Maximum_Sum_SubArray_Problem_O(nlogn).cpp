#include<bits/stdc++.h>
using namespace std;

struct subArray{
    int index1;
    int index2;
    int maxSum;
};

subArray findMaxCrossingSubArray(vector<int> A, int low, int mid, int high){
    int leftSum = INT_MIN;
    int rightSum = INT_MIN;
    subArray s;
    int sum = 0;
    for(int i = mid ; i >= low ; i--){
        sum += A[i];
        if(sum> leftSum){
            leftSum = sum;
            s.index1 = i;
        }
    }
    sum = 0;
    for(int i = mid+1 ; i <= high ; i++){
       sum += A[i];
       if(sum>rightSum){
           rightSum = sum;
           s.index2 = i;
       }
    }
    s.maxSum = leftSum + rightSum;
    return s;
}

subArray MaximumSubarraySum(vector<int> A, int low, int high){
    subArray s;
    if(low == high){
        s.index1 = low;
        s.index2 = high;
        s.maxSum = A[low];
        return s;
    }
    else {
        int mid = (low + high)/2;
        subArray left  = MaximumSubarraySum(A, low, mid);
        subArray right = MaximumSubarraySum(A, mid+1, high);
        subArray crossSum = findMaxCrossingSubArray(A, low, mid, high);
        if(left.maxSum >= right.maxSum && left.maxSum >= crossSum.maxSum){
            return left;
        }else if( right.maxSum >= left.maxSum && right.maxSum >= crossSum.maxSum){
            return right;
        }else{
            return crossSum;
        }
    }
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