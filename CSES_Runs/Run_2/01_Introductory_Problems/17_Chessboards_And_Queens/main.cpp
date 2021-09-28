#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;
 
int main(){
    //freopen("input.txt", "r", stdin);
    vector<string> g(8);
    for(int i = 0; i < 8; i++)
        cin>>g[i];
    vector<int> a(8);
    iota(a.begin(), a.end(), 0);
    ll ans = 0;
    do{
        bool flag = 1;
        for(int i = 0; i < 8; i++){
            flag &= (g[i][a[i]] == '.');
        }
        unordered_set<int> s;
        for(int i = 0; i < 8; i++){
            if(s.count(i-a[i])){
                flag = 0;
            }
            s.insert(i-a[i]);
        }
        s.clear();
        //subtract (i*2) because the difference between the pairs goes up by
        //two as you traverse the top right to bottom left diagonal
        for(int i = 0; i < 8; i++){
            if(s.count(i-a[i]-(i*2))){
                flag = 0;
            }
            s.insert(i-a[i]-(i*2));
        }
        if(flag)
            ans++;
    }while(next_permutation(a.begin(), a.end()));
    cout<<ans<<endl;
    
    return 0;
}