#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
 
int main() { 
    int n;
    cin>>n;
    cout<<(1<<n)-1<<endl;
    function<void(int, int, int, int)> solve = [&](int n, int from, int to, int aux){
        if(n == 1){
            cout<<from<<" "<<to<<endl;
            return; 
        }
        solve(n-1, from, aux, to); 
        cout<<from<<" "<<to<<endl;
        solve(n-1, aux, to, from); 
    };
    solve(n, 1, 3, 2);
    return 0; 
} 