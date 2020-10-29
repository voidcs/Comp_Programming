#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin>>n;
    set<int> s;
    for(int i = 0; i < n; i++){
        int x;
        cin>>x;
        s.insert(x);
    }
    cout<<s.size()<<endl;
    return 0;
}