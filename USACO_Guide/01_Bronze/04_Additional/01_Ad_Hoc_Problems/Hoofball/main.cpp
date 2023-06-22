#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    freopen("hoofball.in", "r", stdin);
    freopen("hoofball.out", "w", stdout);
    int n;
    cin>>n;
    vector<int> v(n);
    for(int &x: v)
        cin>>x;
    sort(v.begin(), v.end());
    vector<array<int, 2>> range;
    for(int i = 0; i < n; i++){
        vector<bool> vis(n);
        int j = i;
        while(!vis[j] && j >= 0 && j < n){
            vis[j] = 1;
            if(j == 0){
                j++;
            }
            else if(j == n-1){
                j--;
            }
            else{
                int left = v[j] - v[j-1];
                int right = v[j+1] - v[j];
                if(left < right)
                    j--;
                else if(right < left)
                    j++;
                else
                    j--;
            }
        }
        int start = n, end = 0;
        for(int j = 0; j < n; j++){
            if(vis[j])
                start = min(start, j), end = max(end, j);
        }
        range.push_back({start, end});
    }
    auto comp = [&](array<int, 2> a, array<int, 2> b){
        if(a[0] != b[0])
            return a[0] < b[0];
        return a[1] > b[1];
    };
    sort(range.begin(), range.end(), comp);
    int ans = 0;
    int start = -1, end = -1;
	//Remove all of the segments that lie completely within another one (not necessary to pass a ball to this cow)
    for(int i = 0; i < n; i++){
        if(range[i][0] >= start && range[i][1] <= end){
            continue;
        }
        start = range[i][0], end = range[i][1];
        ans++;
    }
    cout<<ans<<endl;
    return 0; 
} 
