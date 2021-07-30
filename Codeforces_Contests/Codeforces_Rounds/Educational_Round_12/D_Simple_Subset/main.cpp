#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;
 
int main(){
    set<int> primes;
    int maxN = 2e6+5;
    vector<bool> prime(maxN, 1);
    for(int i = 2; i*i < maxN; i++){
        if(prime[i]){
            for(int j = i*i; j < maxN; j+= i)
                prime[j] = 0;
        }
    }
    for(int i = 2; i < maxN; i++)
        if(prime[i])
            primes.insert(i);

    int n;
    cin>>n;
    vector<int> v(n);
    map<int, int> m;
    for(int &x: v){
        cin>>x;
        m[x]++;
    }
    if(m.size() == 1){
        if(v[0] != 1){
            cout<<"1\n";
            cout<<v[0]<<endl;
            return 0;
        }
        auto x = m.begin();
        cout<<x->second<<endl;
        for(int i = 0; i < x->second; i++)
            cout<<x->first<<" ";
        cout<<endl;
        return 0;
    }
    if(m.count(1)){
        for(int i = 0; i < n; i++){
            if(v[i] != 1 && primes.count(v[i]+1)){
                cout<<m[1] + 1<<endl;
                for(int i = 0; i < m[1]; i++)
                    cout<<"1 ";
                cout<<v[i]<<"\n";
                return 0;
            }
        }
        if(m[1] >= 2){
            cout<<m[1]<<endl;
            for(int i = 0; i < m[1]; i++){
                cout<<"1 ";
            }
            cout<<endl;
            return 0;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(v[i] != v[j]){
                if(primes.count(v[i]+v[j])){
                    cout<<"2\n";
                    cout<<v[i]<<" "<<v[j]<<endl;
                    return 0;
                }
            }
        }
    }
    cout<<"1\n";
    cout<<v[0]<<endl;
    return 0;
}
