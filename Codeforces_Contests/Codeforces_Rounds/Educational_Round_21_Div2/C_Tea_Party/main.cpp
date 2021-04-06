#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    int n, k;
    cin>>n>>k;
    vector<array<int, 2>> v(n);
    for(int i = 0; i < n; i++){
        cin>>v[i][0];
        v[i][1] = i;
    }
    sort(v.begin(), v.end());
    int check = 0;
    for(int i = 0; i < n; i++){
        check += (v[i][0]+1)/2;
    }
    if(check > k){
        cout<<"-1\n";
        return 0;
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    //Dude is not satisfied if someone else has more tea and his own cup is bigger
    //Every cup that is smaller must have less tea
    vector<int> ans(n);
    int used = 0;
    for(int i = 0; i < n; i++){
        int x = (v[i][0]+1)/2;
        ans[v[i][1]] = x;
        used += x;
    }
    for(int i = 0; i < n; i++){
        int r = v[i][0] - ans[v[i][1]];
        if(used + r >= k){
            ans[v[i][1]] += k - used;
            break;
        }
        else{
            used += r;
            ans[v[i][1]] += r;
        }
    }
    for(int i = 0; i < n; i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}