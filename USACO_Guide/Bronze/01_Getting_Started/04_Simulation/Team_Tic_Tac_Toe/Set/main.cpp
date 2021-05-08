#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    freopen("tttt.in", "r", stdin);
    freopen("tttt.out", "w", stdout);
    char a[3][3];
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            cin>>a[i][j];
    
    set<char> solo;
    set<string> duo;
    //Check horizontal lines
    for(int i = 0; i < 3; i++){
        set<char> s;
        for(int j = 0; j < 3; j++){
            s.insert(a[i][j]);
        }
        if(s.size() == 1)
            solo.insert(*s.begin());
        if(s.size() == 2)
            duo.insert(string(1, *s.begin()) + *++s.begin());
    }
    //Check vertical lines
    for(int i = 0; i < 3; i++){
        set<char> s;
        for(int j = 0; j < 3; j++){
            s.insert(a[j][i]);
        }
        if(s.size() == 1)
            solo.insert(*s.begin());
        if(s.size() == 2)
            duo.insert(string(1, *s.begin()) + *++s.begin());
    }
    
    //Top left to bottom right diagonal
    set<char> s;
    for(int i = 0; i < 3; i++)
        s.insert(a[i][i]);
    if(s.size() == 1)
        solo.insert(*s.begin());
    if(s.size() == 2)
        duo.insert(string(1, *s.begin()) + *++s.begin());
    s.clear();
    
    //Top right to bottom left diagonal
    for(int i = 0; i < 3; i++)
        s.insert(a[i][2-i]); 
    if(s.size() == 1)
        solo.insert(*s.begin());
    if(s.size() == 2)
        duo.insert(string(1, *s.begin()) + *++s.begin());
    
    cout<<solo.size()<<endl<<duo.size()<<endl;
    return 0;
}