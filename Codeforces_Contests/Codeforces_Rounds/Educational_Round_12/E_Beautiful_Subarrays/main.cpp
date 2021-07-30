#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;
 
struct Node{
    int next[2];
    int cnt;
    Node(){
        cnt = 0;
        next[1] = -1;
        next[0] = -1;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin>>n>>k;
    vector<int> v(n);
    for(int &x: v)
        cin>>x;
    vector<Node> trie;
    trie.push_back(Node());
    ll ans = 0;
    auto add = [&](int x){
        int i = 0;
        trie[0].cnt++;
        for(int pow = 29; pow >= 0; pow--){
            int j = (x & (1 << pow)) > 0;
            if(trie[i].next[j] == -1){
                trie[i].next[j] = trie.size();
                trie.push_back(Node());
            }
            i = trie[i].next[j];
            trie[i].cnt++;
        }
    };
    auto query = [&](int x){
        int i = 0, curr = 0;
        for(int pow = 29; pow >= 0; pow--){
            int j = (x & (1 << pow)) > 0;
            if(i == -1)
                break;
            if((curr | (1 << pow)) >= k){
                int z = trie[i].next[!j];
                if(z != -1)
                    ans += trie[z].cnt;
                i = trie[i].next[j];
            }
            else{
                i = trie[i].next[!j];
                curr |= (1 << pow);
            }
        }
        if(curr >= k){
            if(i != -1)
                ans += trie[i].cnt;
        }
    };
    add(0);
    int prefix = 0;
    for(int x: v){
        prefix ^= x;
        query(prefix);
        add(prefix);
    }
    cout<<ans<<endl;

    return 0;
}
