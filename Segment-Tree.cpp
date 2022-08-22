#include <bits/stdc++.h>  
using namespace std;  

//Segment trees to perform range queries;
//can get min in O(logn)
//can update in O(logn)

class SegmentTree{
    
public:
    vector<int>v;
    vector<int>lazy;
    // intitialize vector with INT_MAX
    SegmentTree(){create(0);}
    SegmentTree(int n){create(n);}
    void create(int n){
        int k=0,i=0;
        while(k<n) k = pow(2,i++);
        int l = (k==n ? (2*k)-1 : 2*(k+1)-1 );
        v.resize(l,INT_MAX);
        lazy.resize(l,0);
    }
    //fill the vector v with segment tree min values for range queries
    
    void construct(vector<int>&nums,int low,int high,int pos){
        
        if(low == high){
            v[pos] = nums[low];
            return;
        }
        int mid = (low + high)/2;
        construct(nums,low,mid,2*pos + 1);
        construct(nums,mid+1,high,2*pos + 2);
        v[pos] = min(v[2*pos+1],v[2*pos+2]);
    }
    
    // find the min element from the range queries // change high value to input array size
    int findMin(int qlow,int qhigh,int low=0,int high=3,int pos=0){
        
        if(qlow<=low  and  qhigh>=high ) return v[pos];
        if(qhigh<low  or   qlow>high) return INT_MAX;
        int mid = (low + high)/2;
        int left = findMin(qlow,qhigh,low,mid,2*pos+1);
        int right = findMin(qlow,qhigh,mid+1,high,2*pos+2);
        return min(left,right);
    }
    // print tree to check
    void printTree(){
        for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
        cout<<endl;
    }
    //update range of numbers // change high value to input array size
    void increment(int qlow,int qhigh,int delta,int low=0,int high=3,int pos=0){
        
        //return 
        if(low>high) return;
        
        //total overlap
        if(qlow<=low and qhigh>=high){
            v[pos] += delta + lazy[pos];
            lazy[pos]=0;
            if(low!=high){
                lazy[2*pos+1] += delta;
                lazy[2*pos+2] += delta;
            }
            return;
        }
        
        //no overlap
        if(qlow>high or qhigh<low){
            return;
        }
        //partial overlap
        int mid = (low + high)/2;
        increment(qlow,qhigh,delta,low,mid,2*pos+1);
        increment(qlow,qhigh,delta,mid+1,high,2*pos+2);
        v[pos] = min(v[2*pos+1],v[2*pos+2]);
    }
};

int main( ) {  
    vector<int>nums = {-1,2,4,0}; // when changing array size change high value to input array size
    int n = nums.size();
    SegmentTree* s = new SegmentTree(n); 
    s->construct(nums,0,n-1,0);
    s->printTree();
    cout<<s->findMin(2,3)<<endl;
    s->increment(0,1,3);
    s->printTree();
    cout<<s->findMin(0,3);
    return 0;
}  
