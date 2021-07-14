#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    int n;
    cin>>n;
    vector<int> have(2);
    for(int i = 0; i < n; i++){
        int x;
        cin>>x;
        have[x%2]++;
    }
    while(have[1] > have[0]){
        have[1] -= 2;
        have[0]++;
    }
    have[0] = min(have[0], have[1]+1);
    cout<<have[0] + have[1]<<endl;
    return 0;
}