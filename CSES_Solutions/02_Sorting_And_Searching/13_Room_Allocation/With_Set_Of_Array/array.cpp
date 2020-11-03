#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;

struct person{
    ll start, end, index;
};

bool comp(person a, person b){
    if(a.end != b.end)
        return a.end < b.end;
    return a.start < b.start;
}

int main(){
    ll n;
    cin>>n;
    person a[n];
    for(int i = 0; i < n; i++){
        cin>>a[i].start>>a[i].end;
        a[i].index = i;
    }
    sort(a, a + n, comp);

    ll ans[n];
    //Holds [endTime, roomUsed]
    set<array<ll, 2>> s;
    
    for(int i = 0; i < n; i++){
        auto it = s.lower_bound({a[i].start});
        //If there is a end time before this start time, we can take their room
        if(it != s.begin()){
            it--;
            ans[a[i].index] = (*it)[1];
            s.erase(it);
        }
        //Otherwise we have to add a room, assign to s.size()
        else
            ans[a[i].index] = s.size();

        s.insert({a[i].end, ans[a[i].index]});
    }
    
    cout<<s.size()<<endl;
    for(int i = 0; i < n; i++)
        cout<<ans[i] + 1<<" ";
    
    return 0;
}