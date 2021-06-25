#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    int n, x, y;
    cin>>n>>x>>y;
    vector<int> v(n);
    for(int &x: v)
        cin>>x;
    if(x > y){
        cout<<n<<endl;
    }
    else if(x == y){
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(v[i] <= x)
                cnt++;
        }
        cout<<(cnt+1)/2<<endl;
    }
    else{
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(v[i] <= x)
                cnt++;
        }
        cout<<(cnt+1)/2<<endl;
    }
    return 0;
}
