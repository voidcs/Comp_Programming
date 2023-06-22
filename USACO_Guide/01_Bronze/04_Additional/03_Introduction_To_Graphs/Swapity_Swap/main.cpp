#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    freopen("swap.in", "r", stdin);
    freopen("swap.out", "w", stdout);
    int n, k;
    cin>>n>>k;
    int a1, a2, b1, b2;
    cin>>a1>>a2>>b1>>b2;
    vector<int> v(n+1);
    iota(v.begin(), v.end(), 0);
    auto operation = [&](){
        reverse(v.begin() + a1, v.begin() + a2 + 1);
        reverse(v.begin() + b1, v.begin() + b2 + 1);
    };
    int cycle = 0;
    //Hope for a short cycle when the array returns to normal and then mod k with the cycle length
    //As it turns out the cycle length is no longer than 29640 for A = (1, 94) and B = (2, 98)
    do{
        cycle++;
        operation();
    }while(!is_sorted(v.begin(), v.end()));
    k %= cycle;
    for(int i = 0; i < k; i++)
        operation();
    for(int i = 1; i <= n; i++)
        cout<<v[i]<<endl;
    return 0;
}
