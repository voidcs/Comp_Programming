#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
template <typename num_t>
using ordered_set = tree<num_t, null_type, less_equal<num_t>, rb_tree_tag, tree_order_statistics_node_update>;

int main(){
    int n, k;
    cin>>n>>k;
    vector<int> v(n);
    map<int, int> freq;
    for(int &x: v){
        cin>>x;
        freq[x]++;
    }
    bool ok = 1;
    for(auto x: freq){
        if(x.second > k)
            ok = 0;
    }
    map<int, int> m;
    map<int, set<int>> used;
    if(ok){
        cout<<"YES\n";
        int c = 1;
        for(int i = 0; i < n; i++){
            if(i < k){
                cout<<c<<" ";
                m[v[i]] = c;
                used[v[i]].insert(c);
                c++;
            }
            else{
                int x = -1;
                for(int j = 1; j <= k; j++){
                    if(!used[v[i]].count(j)){
                        x = j;
                        break;
                    }
                }
                cout<<x<<" ";
                used[v[i]].insert(x);
            }
        }
    }
    else
        cout<<"NO\n";
    
    return 0;
}
