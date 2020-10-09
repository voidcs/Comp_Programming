#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main(){
    
    ll n;
    cin>>n;
    if(n < 3){
        cout<<"NO\n";
        return 0;
    }

    vector<ll> v1, v2;
    if(n % 4 == 0 || n % 4 == 3){
        cout<<"YES\n";
        if(n % 4 == 0){
            for(int i = 1; i * 2 <= n; i++){
                if(i%2)
                    v1.push_back(i), v1.push_back(n-i+1);
                else
                    v2.push_back(i), v2.push_back(n-i+1);
            }
        }

        else if(n % 4 == 3){
            v1.push_back(1), v1.push_back(2);
            v2.push_back(3);
            for(int i = 4; i <= n; i++){
                if(i%4 == 1 || i%4 == 2)
                    v1.push_back(i);
                else
                    v2.push_back(i);
            }
        }
        
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        
        cout<<v1.size()<<endl;
        for(auto x: v1)
            cout<<x<<" ";
        cout<<endl;
        
        cout<<v2.size()<<endl;
        for(auto x: v2)
            cout<<x<<" ";
        cout<<endl;

        return 0;
    }
    cout<<"NO\n";

    return 0;
}