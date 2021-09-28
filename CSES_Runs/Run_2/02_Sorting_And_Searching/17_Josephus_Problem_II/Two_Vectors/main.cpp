#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    int n, k;
    cin>>n>>k;
    vector<int> A, B;
    for(int i = 1; i <= n/2; i++)
        A.push_back(i);
    for(int i = (n/2)+1; i <= n; i++)
        B.push_back(i);
    int i = 0;
    while(n--){
        i += k;
        i %= (n+1);
        if(i < A.size()){
            cout<<A[i]<<" ";
            A.erase(A.begin() + i);
        }
        else{
            cout<<B[i - A.size()]<<" ";
            B.erase(B.begin() + (i - A.size()));
        }
    }
    return 0;
}