#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, q;
        cin>>n>>q;
        string str;
        cin>>str;
        while(q--){
            int l, r;
            cin>>l>>r;
            l--, r--;
            string b;
            for(int i = l; i <= r; i++)
                b += str[i];
            bool flag = 0, start = 0, end = 0;
            int index = 0;
            for(int i = 0; i < n; i++){
                if(!end && start && str[i] != b[index]){
                    flag = 1;
                }
                if(index != b.length() && str[i] == b[index]){
                    start = 1;
                    index++;
                    if(index == b.length())
                        end = 1;
                }
                else if(end && str[i] == b[index-1]){
                    flag = 1;
                }
            }
            if(flag)
                cout<<"YES\n";
            else
                cout<<"NO\n";
            
        }
    }
    return 0;
}