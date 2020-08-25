#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    string str;
    while(cin>>str){
        int n = str.length();
        for(int i = 0; i < n; i++){
            int val = str[i];
            vector<int> v;
            while(val){
                v.push_back(val%2);
                val /= 2;
            }
            while(v.size() != 8)
                v.push_back(0);
            reverse(v.begin(), v.end());
            
            for(auto x: v)
                cout<<x;

        }
        
        cout<<"00100000 ";
    }
    return 0;
}