#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

//REFERENCE VIDEO
//https://www.youtube.com/watch?v=JJ_f2mTkcfY&list=PL2q4fbVm1Ik6v2-emg_JGcC9v2v2YTbvq&index=3

int st[10001];  //Array that holds the actual segment tree
int a[10001];   //Input array

void buildTree(int si, int ss, int se){
    
    //If the segment start equals the segment end
    //Then this must be a leaf node (it's minimum only depends on itself
    if(ss == se){
        st[si] = a[ss];
        return;
    }
    
    int mid = (ss + se) / 2;
    //Can use mid = ss + (se-ss) / 2 to avoid int overflow
    
    //Build the left child
    buildTree(2*si, ss, mid);
    
    //Build the right child
    buildTree(2*si+1, mid+1, se);
    
    //Take minimum of children
    st[si] = min(st[2*si], st[2*si+1]);
}

int query(int si, int ss, int se, int qs, int qe){
    //If the current segment is outside of the query segment
    if(qs > se || qe < ss)
        return INT_MAX;
    
    //If the current segment is completely inside the query segment
    if(ss >= qs && se <= qe)
        return st[si];
    
    int mid = (ss + se) / 2;
    int l = query(2*si, ss, mid, qs, qe);
    int r = query(2*si+1, mid+1, se, qs, qe);
    
    return min(l, r);
}

int main(){
    int n;
    cout<<"Enter n, the size of the array\n";
    cin>>n;
    cout<<"Enter "<<n<<" elements\n";
    for(int i = 1; i <= n; i++)
        cin>>a[i];
    
    buildTree(1, 1, n);
    
    int nextLine = 1;
    int count = 0;
    
    cout<<"\nTHE SEGMENT TREE\n";
    for(int i = 1; i <= n*4; i++){
        cout<<st[i]<<" ";
        count++; 
        
        if(count == nextLine){
            cout<<"\n";
            nextLine <<= 1;
            count = 0;
        }
    }
    
    return 0;
}