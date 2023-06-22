#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int &x: v)
        cin>>x;
    
    int ans = 0;
    for(int i = 0; i < n; i++){
        int sum = 0;
        unordered_set<int> s;
        for(int j = i; j < n; j++){
            sum += v[j];
            s.insert(v[j]);
            if(sum % (j-i+1) == 0){
                int average = sum / (j-i+1);
                if(s.count(average))
                    ans++;
            }
        }
    }
    cout<<ans<<endl;
    
    return 0;
}