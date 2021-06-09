#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    freopen("input.txt", "r", stdin);
    //freopen("whereami.out", "w", stdout);
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
        m[a] = {m[b].first, type};
        int j = year[m[b].second];
        if(time == "previous"){
            while(names[j] != type){
                if(!j)
                    j = 11;
                else
                    j--;
                m[a].first--;
            }
        }
        else{
            while(names[j] != type){
                if(j == 11)
                    j = 0;
                else
                    j++;
                m[a].first++;
            }
        }
    }
//    for(auto x: m)
//        cout<<x.first<<" "<<x.second.first<<" "<<x.second.second<<endl;
    cout<<abs(m["Bessie"].first - m["Elsie"].first)<<endl;
    
    return 0;
}