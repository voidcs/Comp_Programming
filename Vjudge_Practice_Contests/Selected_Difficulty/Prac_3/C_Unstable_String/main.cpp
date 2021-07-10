#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

//Strategy: Try to continue valid segments as long as possible
//Then for each valid segment, (n * (n+1)) / 2 valid subsequences are valid for it
int main(){
    ll t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        ll ans = 0, cnt = 0, last = -1;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '0' || s[i] == '1'){
                //If we cannot continue a valid segment, add # of valid subsequences
                //And reset cnt = 1;
                if(last != -1 && s[i] - '0' == last){
                    ans += (cnt * (cnt+1)) / 2;
                    cnt = 1;
                    last = s[i] - '0';
                }
                //If we can continue a valid segment, increment cnt by 1
                else{
                    cnt++;
                    last = s[i] - '0';
                }
            }
            else if(s[i] == '?'){
                ll marks = 0;
                //Find continuous block of ?'s
                while(i < s.length() && s[i] == '?'){
                    marks++;
                    cnt++;
                    i++;
                }
                //If the left and right of the segment of ?'s contain a 0 or 1, we have
                //to check if we can put a valid arrangement of numbers to fill the ?'s
                //If the endpoints don't create a conflict, simply keep incrementing to the cnt
                //Otherwise, (let n = cnt + mark), we add (n * (n+1)) / 2 to the ans, and restart cnt at mark
                if(i < s.length() && (last == 1 || last == 0)){
                    if((s[i]-'0' == last && marks%2 == 0) || (s[i]-'0' != last && marks%2 == 1)){
                        ans += (cnt * (cnt+1)) / 2;
                        ans -= (marks * (marks+1)) / 2;
                        cnt = marks;
                    }
                }
                i--;
                last = 2;
            } 
        }
        ans += (cnt * (cnt+1)) / 2;
        cout<<ans<<endl;
    }
    return 0;
}