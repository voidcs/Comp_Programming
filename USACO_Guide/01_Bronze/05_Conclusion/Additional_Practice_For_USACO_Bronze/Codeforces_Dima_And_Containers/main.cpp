#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    vector<string> op = {"popQueue", "popStack", "popFront"};
    int n;
    cin>>n;
    vector<int> v(n);
    for(int &x: v)
        cin>>x;
    for(int i = 0; i < n; i++){
        int cnt = 0;
        vector<array<int, 2>> best;
        set<int> s;
        int j = i;
        while(j < n){
            if(!v[j])
                break;
            best.push_back({v[j], j});
            j++;
        }
        if(j == n){
            for(int k = i; k < n; k++){
                cout<<"pushStack\n";
            }
            return 0;
        }
        sort(best.rbegin(), best.rend());
        for(int k = 0; k < min(3, (int)best.size()); k++){
            s.insert(best[k][1]);
        }
        for(int k = i; k < j; k++){
            if(s.count(k)){
                if(cnt == 0)
                    cout<<"pushQueue\n";
                else if(cnt == 1)
                    cout<<"pushStack\n";
                else
                    cout<<"pushFront\n";
                cnt++;
            }
            else{
                cout<<"pushBack\n";
            }
        }
        cout<<cnt;
        for(int k = 0; k < cnt; k++){
            cout<<" "<<op[k];
        }
        cout<<endl;
        i = j;

    }
    return 0;
}
