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
    int n;
    cin>>n;
    ordered_set<array<int, 2>> s;
    map<int, int> m;
    int l = 0, r = 1;
    for(int i = 0; i < n; i++){
        char q;
        int x;
        cin>>q>>x;
        if(q == 'L'){
            l--;
            m[x] = l;
            s.insert({l, x});
        }
        else if(q == 'R'){
            r++;
            m[x] = r;
            s.insert({r, x});
        }
        else{
            int i = (s.order_of_key({m[x], x}));
            cout<<min(i, (int)s.size() - 1 - i)<<endl;
        }
    }
    return 0;
}