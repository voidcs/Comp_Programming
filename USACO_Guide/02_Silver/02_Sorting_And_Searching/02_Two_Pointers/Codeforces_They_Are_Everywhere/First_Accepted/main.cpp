//https://codeforces.com/problemset/problem/701/C
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    map<char, int> have;
    set<char> all;
    for(char c: s)
        all.insert(c);
    int ans = 1e9;
    int j = 0;
    for(int i = 0; i < n; i++){
        //Add current letter to map
        have[s[i]]++;
        //If we have all the pokemon, try removing from the back
        if(have.size() == all.size()){
            ans = min(ans, i - j + 1);
            while(have.size() == all.size()){
                have[s[j]]--;
                if(have[s[j]] == 0)
                    have.erase(s[j]);
                j++;
            }
            //Add the last letter back to have all the pokemon
            j--;
            have[s[j]]++;
            ans = min(ans, i - j + 1);
        }
    }
    cout<<ans<<endl;
    return 0;
}
