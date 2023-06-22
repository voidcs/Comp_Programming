#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    freopen("backforth.in", "r", stdin);
    freopen("backforth.out", "w", stdout);
    set<int> s;
    vector<int> x(10), y(10);
    for(int &r: x)
        cin>>r;
    for(int &r: y)
        cin>>r;
    function<void(int, pair<int, vector<int>>, pair<int, vector<int>>)> search = [&](int day, auto u, auto v){
        if(day == 4){
            s.insert(u.first);
            return;
        }
		//Try all buckets in barn u
        for(int i = 0; i < u.second.size(); i++){
			//Choose bucket i of size r
            int r = u.second[i];
			
			//remove bucket i from copy of barn u
            vector<int> a = u.second;
            a.erase(a.begin() + i);
			
			//add bucket i to copy of barn v
            vector<int> b = v.second;
            b.push_back(r);
			
			//Go to next day, change our current barn to v, the other barn to u
			//We poored r units of milk into current barn, remove r units from barn we came from
            search(day+1, {v.first + r, b}, {u.first - r, a});
        }
    };
    search(0, {1000, x}, {1000, y});
    cout<<s.size()<<endl;
    
    return 0;
}