#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    int n;
    cin>>n;
    map<string, int> year;
    vector<string> names = {"Ox", "Tiger", "Rabbit", "Dragon", "Snake", "Horse", "Goat", "Monkey", "Rooster", "Dog", "Pig", "Rat"};
    for(int i = 0; i < names.size(); i++){
        year[names[i]] = i;
    }
    map<string, pair<int, string>> m;
    m["Bessie"] = {0, "Ox"};
    for(int i = 0; i < n; i++){
        string a, b, time, type, t;
        cin>>a>>t>>t>>time>>type>>t>>t>>b;
        if(time == "previous"){
            if(year[type] >= year[m[b].second])
                m[a] = {m[b].first - (year[m[b].second] + (12 - year[type])), type};
            else
                m[a] = {m[b].first - (year[m[b].second] - year[type]), type};
        }
        else{
            if(year[type] > year[m[b].second])
                m[a] = {m[b].first + (year[type] - year[m[b].second]), type};
            else
                m[a] = {m[b].first + (12 - year[m[b].second] + year[type]), type};
        }
    }
    cout<<abs(m["Elsie"].first)<<endl;
    return 0;
}