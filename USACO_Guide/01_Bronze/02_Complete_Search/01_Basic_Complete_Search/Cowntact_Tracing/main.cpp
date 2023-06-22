#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    freopen("tracing.in", "r", stdin);
    freopen("tracing.out", "w", stdout);
    int n, m;
    string end;
    cin>>n>>m>>end;
    vector<array<int, 3>> v(m);
    for(int i = 0; i < m; i++){
        cin>>v[i][0]>>v[i][1]>>v[i][2];
        v[i][1]--, v[i][2]--;
    }
    sort(v.begin(), v.end(), [](array<int, 3> a, array<int, 3> b){
        return a[0] < b[0];
    });
    int ans = 0, lower = 1e9, upper = 0;
    for(int i = 0; i < n; i++){
        bool valid = 0;
        for(int k = 0; k <= 251; k++){
            vector<int> infected(n), shakesLeft(n, k);
            infected[i] = 1;
            for(int j = 0; j < m; j++){
                //If they're both infected, decrase their number of shakes left
                if(infected[v[j][1]] && infected[v[j][2]]){
                    shakesLeft[v[j][1]]--, shakesLeft[v[j][2]]--;
                }
                //If neither are infected we do nothing
                else if(!infected[v[j][1]] && !infected[v[j][2]])
                    continue;
                else{
                    //If first cow is infected and second isn't
                    if(infected[v[j][1]]){
                        if(shakesLeft[v[j][1]] > 0){
                            shakesLeft[v[j][1]]--;
                            infected[v[j][2]] = 1;
                        }
                    }
                    //Else if second cow is infected and first isn't
                    else{
                        if(shakesLeft[v[j][2]] > 0){
                            shakesLeft[v[j][2]]--;
                            infected[v[j][1]] = 1;
                        }
                    }
                }
            }
            bool ok = 1;
            for(int j = 0; j < n; j++){
                if(infected[j] != end[j] - '0')
                    ok = 0;
            }
            if(ok){
                lower = min(lower, k);
                upper = max(upper, k);
                valid = 1;
            }
        }
        if(valid)
            ans++;
    }
    cout<<ans<<" "<<lower<<" ";
    if(upper == 251)
        cout<<"Infinity\n";
    else
        cout<<upper<<endl;
    return 0;
}
