#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

//PROBLEM LINK
//https://codeforces.com/problemset/problem/1132/C

int main(){
    //freopen("input.txt", "r", stdin);
    int n, q;
    cin>>n>>q;
    vector<array<int, 2>> v(q);
    for(int i = 0; i < q; i++) 
        cin>>v[i][0]>>v[i][1];
    
    int ans = 0;
    for(int i = 0; i < q; i++){
        //Fenwick tree
        vector<int> bit(n + 1);
        //Increase index x by 1
        auto add = [&](int x) {
            while (x <= n) {
                bit[x]++;
                x += x & -x;
            }
        };
        //Get sum up to range x
        auto sum = [&](int x){
            int ret = 0;
            while (x) {
                ret += bit[x];
                x -= x & -x;
            }
            return ret;
        };
        //Prefix sum with O(1) range update trick
        vector<int> mark(n+1);
        for(int j = 0; j < q; j++){
            if(i == j){
                continue;
            }
            mark[v[j][0] - 1]++;
            mark[v[j][1]]--;
        }
        //cnt retrieves how many painters cover index j
        int cnt = 0, now = 0;
        for(int j = 1; j <= n; j++){
            cnt += mark[j-1];
            if(cnt){
                //Increment how many sections we have painted
                now++;
                //If cnt is 1, then section j is dependent on one painter
                if (cnt == 1){
                    //Set section j to have a solo painter
                    add(j);
                }
            }
        }
        //Try removing second painter
        //Our total sections painted decreases by number of solo painted sections from l to r
        for(int j = i+1; j < q; j++){
            ans = max(ans, now - (sum(v[j][1]) - sum(v[j][0] - 1)));
        }
    }
    cout<<ans<<endl;
    return 0;
}
