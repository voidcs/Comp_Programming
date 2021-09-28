#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    int n;
    function<void(int, int, int, int)> hanoi = [&](int n, int src, int helper, int dest){
        if(n == 0)
            return;
        hanoi(n-1, src, dest, helper);
        cout<<src<<" "<<dest<<"\n";
        hanoi(n-1, helper, src, dest);
    };
    cin>>n;
    cout<<(1<<n)-1<<endl;
    hanoi(n, 1, 2, 3);
    return 0;
}