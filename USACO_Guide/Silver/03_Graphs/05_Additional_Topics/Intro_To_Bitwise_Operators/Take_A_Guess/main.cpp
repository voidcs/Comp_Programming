#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    int n, k;
    cin>>n>>k;
    vector<int> ans(n);
    auto query = [&](int a, int b){
        cout<<"and "<<a<<" "<<b<<endl;
        cout<<"or "<<a<<" "<<b<<endl;
        int res_and, res_or;
        cin>>res_and>>res_or;
        return 2 * (res_and) + (res_or & ~(res_and));
    };
    int sumA = query(1, 2);
    int sumB = query(2, 3);
    int sumC = query(1, 3);
    ans[0] = (sumA + sumC - sumB) / 2;
    ans[1] = (sumA + sumB - sumC) / 2;
    ans[2] = (sumB + sumC - sumA) / 2;
    for(int i = 3; i < n; i++){
        int sum = query(i, i + 1);
        ans[i] = sum - ans[i-1];
    }
    sort(ans.begin(), ans.end());
    cout<<"finish "<<ans[k-1]<<endl;
}
