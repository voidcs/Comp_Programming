#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    int t;
    cin>>t;
    while(t--){
        ll x;
        cin>>x;
        x--;
        ll len = 1 num = 1;
		//Find which power of 10 our digit lies in
		//For example:  for 1-9 we have 9 digits
		//				for 10-99 we have 180 digits
		//				for 100-999 we have 2700 digits etc
        while(x > len*9*num){
            x -= len*9*num;
            len++, num*=10;
        }
		//Set num to the actual number we lie on by adding x/len
        num += x/len;
		//Make x the ith digit of num
        x %= len;
        cout<<to_string(num)[x]<<endl;
    }
    return 0;
}
