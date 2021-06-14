#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e9;

int main(){
    freopen("taming.in", "r", stdin);
    freopen("taming.out", "w", stdout);
    int n;
    cin>>n;
    vector<int> v(n);
    for(int &x: v)
        cin>>x;
    if(v[0] > 0){
        cout<<"-1\n";
        return 0;
    }
    //We know that there is a guaranteed breakout on day zero, so we will change it
    //in the case that it was -1
    v[0] = 0;
    int low = 0, high = 0;
    for(int i = n-1; i >= 0; i--){
        //If we end on a -1, this is optional and can be added to the high
        if(v[i] == -1)
            high++;
        else{
            high++, low++;
            //The index of the last breakout
            int last = i - v[i];
            //Check the last v[i] days to see if we find a contradiction
            //If v[i-j] != -1 and the breakout that it calculates does not match
            //the variable last, then we have found a contradiction (print -1)
            for(int j = 1; j <= v[i]; j++){
                if(v[i-j] != -1 && i - j - v[i-j] != last){
                    cout<<"-1\n";
                    return 0;
                }
            }
            i -= v[i];
        }
    }
    cout<<low<<" "<<high<<endl;
    
    return 0;
}