#include <bits/stdc++.h>  
using namespace std;  

//Max heap using vectors
//insertElement,getElement

void insertElement(vector<int>&maxHeap,int a){
    maxHeap.push_back(a);
    int index = maxHeap.size()-1;
    int parent = index/2;
    while(parent!=0 and maxHeap[parent] <= a){
        swap(maxHeap[parent],maxHeap[index]);
        index = parent;
        parent = index/2;
    }
    return;
}
int getElement(vector<int>&maxHeap){
    int a = maxHeap[1];
    maxHeap[1] = maxHeap[maxHeap.size()-1];
    maxHeap.pop_back();
    int maxInd = maxHeap.size()-1;
    int index = 1;
    int child1 = index*2,child2=index*2 +1;
    
    while((child1 <= maxInd and maxHeap[index] <= maxHeap[child1]) or (child2 <= maxInd and maxHeap[index]<=maxHeap[child2])){
        if(maxHeap[child1]>maxHeap[child2]){
            swap(maxHeap[index],maxHeap[child1]);
            index = child1;
            child1 = index*2;
            child2 = index*2 +1;
        }else{
            swap(maxHeap[index],maxHeap[child2]);
            index = child2;
            child1 = index*2;
            child2 = index*2 +1;
        }
    }
    return a;
}
int main( ) {  
    vector<int>maxHeap;
    maxHeap.push_back(0);
    int n;cin>>n;
    while(n--){
        int a;
        cin>>a;
        insertElement(maxHeap,a);
    }
    cout<<getElement(maxHeap)<<getElement(maxHeap)<<endl;
    for(int i=0;i<maxHeap.size();i++){
        cout<<maxHeap[i]<<" ";
    }
    cout<<endl;
}  