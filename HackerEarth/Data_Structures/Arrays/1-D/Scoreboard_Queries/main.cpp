#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

//PROBLEM LINK
//https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/tournament-and-ranks-67cd4b7e/

int main(){
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--){
        int n, q;
        cin>>n>>q;
        vector<int> v(n);
        map<int, int> m;
        for(int &x: v){
            cin>>x;
            m[x]++;
        }
        while(q--){
            int i, newScore;
            cin>>i>>newScore;
            int old = v[i-1];
            m[old]--;
            if(!m[old])
                m.erase(old);
            v[i-1] = newScore;
            m[newScore]++;
            cout<<m.size()+1<<endl;
        }
    }
    return 0;
}