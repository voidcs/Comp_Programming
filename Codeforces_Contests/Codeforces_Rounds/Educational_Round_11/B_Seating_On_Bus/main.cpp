#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>> left(n), right(n);
    int row = 0;
    for(int i = 1; i <= m; i++){
        if(i%2)
            left[row].push_back(i);
        else{
            right[row].push_back(i);
            row++;
        }
        if(row == n)
            row = 0;
    }
    for(int i = 0; i < n; i++){
        while(left[i].size()){
            cout<<left[i].back()<<" ";
            left[i].pop_back();
        }
        while(right[i].size()){
            cout<<right[i].back()<<" ";
            right[i].pop_back();
        }
    }
    return 0;
}
