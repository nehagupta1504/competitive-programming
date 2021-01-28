

//Huffman Coding

#include<bits/stdc++.h>
using namespace std;

class MinHeapNode{
    public:
    char data;
    unsigned freq;
    
    //for adding previous nodes to the new internal node
    MinHeapNode *left, *right;
    
     MinHeapNode(char data, unsigned freq){
        left =right=NULL;
        this->data=data;
        this->freq=freq;
    }
};

class compare{
    public:
    bool operator()(MinHeapNode* l, MinHeapNode* r){
        return (l->freq > r->freq);
    }
};

void printCodes(struct MinHeapNode* root, string str){
    if(!root)
        return;
    if(root->data!='$'){
        cout<<root->data<<":"<<str<<"\n";
    }
    
    printCodes(root->left,str+"0");
    printCodes(root->right,str+"1");
}

void HuffmanCodes(char data[], int freq[], int size){
    MinHeapNode *left, *right, *top;
    
    
    //create a min heap & insert all characters of MinHeapNode
    priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;
    
    for(int i=0;i<size;i++){
        minHeap.push(new MinHeapNode(data[i],freq[i]));
    }
    
    //iterate while size of heap doesn't becomes 1
    
    while(minHeap.size()!=1){
        //Extarct 2 minimum items
        left=minHeap.top();
        minHeap.pop();
        
        right=minHeap.top();
        minHeap.pop();
        
        //create a new internal node with freq=sum of freq of left & right node
        //Amke the extracted node as left & right children
        //& internal node have value $
    
        top=new MinHeapNode('$', left->freq+right->freq);
        
        top->left=left;
        top->right=right;
        
        minHeap.push(top);
    }
    
    printCodes(minHeap.top(),"");
}

int main(){
    char arr[]={'a','b','c','d','e','f'};
    int freq[]={5,9,12,13,16,45};
    int size=sizeof(arr)/sizeof(arr[0]);
    HuffmanCodes(arr,freq,size);
}