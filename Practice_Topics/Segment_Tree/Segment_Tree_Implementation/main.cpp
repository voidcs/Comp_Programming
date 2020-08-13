#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

//REFERENCE VIDEO
//https://www.youtube.com/watch?v=ercqgd9QJT0&list=PL2q4fbVm1Ik6v2-emg_JGcC9v2v2YTbvq&index=4

int st[10001]; 
int a[10001];

void buildTree(int si, int ss, int se){
    if(ss == se){
        st[si] = a[ss];
        return;
    }
    
    int mid = (ss + se) / 2;
    buildTree(2*si, ss, mid);
    buildTree(2*si+1, mid+1, se);

    st[si] = min(st[2*si], st[2*si+1]);
}

int query(int si, int ss, int se, int qs, int qe){
    if(qs > se || qe < ss)
        return INT_MAX;

    if(ss >= qs && se <= qe)
        return st[si];
    
    int mid = (ss + se) / 2;
    
    return min(query(2*si, ss, mid, qs, qe), query(2*si+1, mid+1, se, qs, qe));
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