#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n, m;
    cin>>n>>m;
    map<int, int> mp1, mp2;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char c;
            cin>>c;
            if(c == '*'){
                mp1[i+1]++;
                mp2[j+1]++;
            }
        }
    }
    for(auto x: mp1){
        if(x.second == 1)
            cout<<x.first<<" ";
    }
    for(auto x: mp2){
        if(x.second == 1)
            cout<<x.first<<" ";
    }
    return 0;
}