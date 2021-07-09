#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    int n;
    cin>>n;
    string a, b;
    cin>>a>>b;
    map<int, int> ma, mb;
    for(auto x: a)
        ma[x]++;
    for(auto x: b)
        mb[x]++;
    if(ma != mb)
        cout<<"-1\n";
    else{
        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(a[i] != b[i]){
                while(a[i] != b[i]){
                    int start = -1;
                    for(int j = i+1; j < n; j++){
                        if(a[j] == b[i]){
                            start = j;
                            break;
                        }
                    }
                    swap(a[start-1], a[start]);
                    ans.push_back(start);
                }
            }
        }
        cout<<ans.size()<<endl;
        for(auto x: ans)
            cout<<x<<" ";
    }
    return 0;
}
