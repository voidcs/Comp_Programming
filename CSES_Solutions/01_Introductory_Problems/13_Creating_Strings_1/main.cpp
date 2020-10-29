#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main(){
    string str;
    cin>>str;
    sort(str.begin(), str.end());
    vector<string> ans;
    do{
        ans.push_back(str);
    }while(next_permutation(str.begin(), str.end()));
    
    cout<<ans.size()<<endl;
    for(auto x: ans){
        cout<<x<<endl;
    }
    
    return 0;
}