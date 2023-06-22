#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

struct cow{
    ll x, y, id;
    char d;
    bool operator < (const cow &a){
        return y < a.y;
    }
};

int main(){
    int n;
    cin>>n;
    vector<cow> v(n);
    for(int i = 0; i < n; i++){
        cin>>v[i].d>>v[i].x>>v[i].y;
        v[i].id = i;
    }
    vector<array<cow, 2>> intersections;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(v[i].d == v[j].d)
                continue;
            //Make a the cow going north
            cow a = v[i], b = v[j];
            if(a.d == 'E')
                swap(a, b);
            if(a.x > b.x && b.y > a.y)
                intersections.push_back({a, b});
        }
    }
    //We first process the intersection where a cow would be stopped as quickly as possible
    auto comp = [&](array<cow, 2> a, array<cow, 2> b){
        //The cow with furthest distance is the one that gets stopped
        ll distA = max(a[0].x - a[1].x, a[1].y - a[0].y);
        ll distB = max(b[0].x - b[1].x, b[1].y - b[0].y);
        //Take the min between both to see which intersection has a cow stopping earlier
        return distA < distB;
    };
    sort(intersections.begin(), intersections.end(), comp);
    vector<ll> stopped(n, -1);
    vector<int> par(n, -1), isPar(n);
    for(array<cow, 2> x: intersections){
        cow a = x[0], b = x[1];
        //If both cows are stopped we do nothing
        if(stopped[a.id] != -1 && stopped[b.id] != -1)
            continue;
        //If both cows haven't been stopped we find their intersection point
        //and then see which one would be stopped
        if(stopped[a.id] == -1 && stopped[b.id] == -1){
            if(abs(a.x - b.x) != abs(a.y - b.y)){
                if(b.y - a.y < a.x - b.x){
                    par[b.id] = a.id;
                    isPar[a.id] = 1;
                    stopped[b.id] = a.x - b.x;
                }
                else{
                    par[a.id] = b.id;
                    isPar[b.id] = 1;
                    stopped[a.id] = b.y - a.y;
                }
            }
        }
        else{
            //If cow B has already stopped and cow A hasn't
            if(stopped[b.id] != -1){
                ll x = b.x + stopped[b.id], y = b.y;
                if(x >= a.x){
                    par[a.id] = b.id;
                    isPar[b.id] = 1;
                    stopped[a.id] = y - a.y;
                }
            }
            //Otherwise if cow A has stopped and cow B hasn't
            else{
                ll x = a.x, y = a.y + stopped[a.id];
                if(y >= b.y){
                    par[b.id] = a.id;
                    isPar[a.id] = 1;
                    stopped[b.id] = x - b.x;
                }
            }
        }
    }
    vector<set<int>> ans(n);
    for(int i = 0; i < n; i++){
        if(isPar[i])
            continue;

        set<int> s = {i};
        int curr = par[i];
        while(curr != -1){
            for(auto x: s)
                ans[curr].insert(x);
            s.insert(curr);
            curr = par[curr];
        }
    }
    for(int i = 0; i < n; i++){
        cout<<ans[i].size()<<"\n";
    }
    return 0;
}
