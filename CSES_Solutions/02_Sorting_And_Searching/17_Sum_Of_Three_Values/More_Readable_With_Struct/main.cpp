#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct num{
    ll value, index;
};

bool comp(num a, num b){
    return a.value < b.value;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n, x;
    cin>>n>>x;
    num a[n];
    for(int i = 0; i < n; i++){
        cin>>a[i].value;
        a[i].index = i;
    }
    sort(a, a + n, comp);
    for(int i = 0; i < n; i++){
        ll goal = x - a[i].value;
        ll l = i+1, r = n-1;
        while(l < r){
            ll sum = a[l].value + a[r].value;
            if(sum < goal)
                l++;
            else if(sum > goal)
                r--;
            else{
                cout<<a[i].index+1<<" "<<a[l].index+1<<" "<<a[r].index+1<<endl;
                return 0;
            }
        }
    }
    
    cout<<"IMPOSSIBLE\n";
    return 0;
}