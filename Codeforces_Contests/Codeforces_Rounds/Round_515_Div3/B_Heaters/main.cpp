#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    int n, r;
    cin>>n>>r;
    vector<int> v(n);
    for(int &x: v)
        cin>>x;
    vector<int> mark(n);
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(v[i]){
            cnt++;
            int a = max(0, i-r+1);
            int b = min(n-1, i+r-1);
            for(int j = a; j <= b; j++)
                mark[j]++;
        }
    }
    int sum = 0;
    for(int i = 0; i < n; i++)
        sum += (mark[i] > 0);
    if(sum != n){
        cout<<"-1\n";
        return 0;
    }
    else{
        for(int i = 0; i < n; i++){
            bool ok = 1;
            if(v[i]){
                int a = max(0, i-r+1);
                int b = min(n-1, i+r-1);
                for(int j = a; j <= b; j++){
                    mark[j]--;
                    if(mark[j] <= 0)
                        ok = 0;
                }
                if(ok){
                    cnt--;
                    continue;
                }
                for(int j = a; j <= b; j++){
                    mark[j]++;
                    if(mark[j] <= 0)
                        ok = 0;
                }
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
