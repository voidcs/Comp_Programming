#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v(n);
        for(int &x: v)
            cin>>x;
        int low = *min_element(v.begin(), v.end());
        int high = *max_element(v.begin(), v.end());
        int x = find(v.begin(), v.end(), low) - v.begin();
        int y = find(v.begin(), v.end(), high) - v.begin();
        if(x > y)
            swap(x, y);
        int ans = min({1+x+(y-x), 1+x+(n-y), y-x+(n-y)});
        cout<<ans<<endl;
    }
    return 0; 
} 