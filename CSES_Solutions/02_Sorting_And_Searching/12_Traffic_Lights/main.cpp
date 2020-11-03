#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;

int main(){
    int x, n;
    cin>>x>>n;
    int a[n];
    
    set<int> s;
    map<int, int> m;
    s.insert(0);
    s.insert(x);
    m[x] = 1;
    for(int i = 0; i < n; i++){
        cin>>a[i];
        
        //Find the section this light will cover
        auto it = s.lower_bound(a[i]);
        int r = *it;
        --it;
        int l = *it;

        //remove this segment of length r-l
        --m[r-l];
        
        //if there are 0 segments of this length, erase it
        if(!m[r-l])
            m.erase(r-l);
        s.insert(a[i]);
        
        //Add segment of length r-a[i] and a[i]-l
        m[r-a[i]]++;
        m[a[i]-l]++;

        cout<<(--m.end())->first<<" ";
    }
    
    return 0;
}