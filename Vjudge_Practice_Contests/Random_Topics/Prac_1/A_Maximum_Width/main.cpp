#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;
 
int main(){
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    string s, t;
    cin>>s>>t;
    //vector a holds first occurrence of ith letter 
    //vector b holds last occurrence of ith letter
    vector<int> a, b;
    int j = 0;
    for(int i = 0; i < m; i++){
        while(s[j] != t[i])
            j++;
        a.push_back(j++);
    }
    j = n-1;
    for(int i = m-1; i >= 0; i--){
        while(s[j] != t[i])
            j--;
        b.push_back(j--);
    }
    reverse(b.begin(), b.end());
    
    int ans = 0;
    //use up to i letters from prefix
    //then take the next element from suffix
    for(int i = 0; i < m-1; i++)
        ans = max(ans, b[i+1] - a[i]);
    cout<<ans<<endl;
    
    return 0;
}