#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll t;
    scanf("%lld", &t);
    while(t--){
        ll a[4];
        for(int i = 0; i < 4; i++)
            scanf("%lld", a + i);
        
        ll tot = 1 << 4;
        bool flag = 0;
        for(int i = 1; i < tot; i++){
            ll sum = 0;
            for(int j = 0; j < 4; j++){
                ll f = (1<<j);
                if( (f&i) != 0){
                    sum += a[j];
                }
            }
            if(sum == 0)
                flag = 1;
        }
        if(flag)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
