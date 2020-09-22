#include<bits/stdc++.h>
using namespace std;

int getSum( vector<int> &prefixList, int indexToCalculateSum){
    int sum=0;
    while(indexToCalculateSum>0){
        sum+=prefixList[indexToCalculateSum];
        indexToCalculateSum-=indexToCalculateSum&(-indexToCalculateSum);
    }
    return sum;
}

void updateBinaryIndexedTree(vector<int> list, vector<int> &prefixList, int index, int value){
    index=index+1;
    while(index<=list.size()){
        prefixList[index]+=value;
        index= index + (index & (-index)); //extracting the last set bit of index & adding it to the actual index to get the parent;
    }
}

void constructBinaryIndexedTree(vector<int> list, vector<int> &prefixList){
    for(int i=0;i<list.size();i++){
        updateBinaryIndexedTree(list, prefixList, i, list[i]);
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> list;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        list.push_back(temp);
    }
    vector<int> prefixList(n+1,0);
    constructBinaryIndexedTree(list, prefixList);
    cout<<"Do you want to get sum or update array"<<"\n";
    cout<<"1 for sum"<<"\n"<<"2 for update"<<"\n";
    int choice;
    cin>>choice;
    string answer;
   while(choice==1 || choice==2){
           switch(choice){
                case 1: do{
                            int indexToCalculateSum;
                            cin>>indexToCalculateSum;
                            cout<<getSum(prefixList , indexToCalculateSum)<<"\n";
                            cout<<"Do you need sum ?"<<"\n"<<" type yes or no."<<"\n";
                            cin>>answer;
                        }while(answer=="yes"||answer=="YES");
                        break;
                case 2: cout<<"Enter the value & index to be updated"<<"\n";
                        int ind, value;
                        cin>>value>>ind;
                        list[ind]+=value;
                        updateBinaryIndexedTree(list, prefixList, ind, value);
            }
        for(int i=1;i<=n;i++){
            cout<<prefixList[i]<<" ";
        }
        cout<<"\n";
        cout<<"Do you want to get sum or update array"<<"\n";
        cout<<"1 for sum"<<"\n"<<"2 for update"<<"\n";
        cin>>choice;
   }
    
}