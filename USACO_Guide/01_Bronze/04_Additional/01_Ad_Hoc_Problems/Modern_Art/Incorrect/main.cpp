#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e9;

int main(){
    freopen("art.in", "r", stdin);
    //freopen("art.out", "w", stdout);
    int n;
    cin>>n;
    vector<vector<char>> g(n, vector<char>(n));
    map<char, int> freq;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin>>g[i][j];
            freq[g[i][j]]++;
        }
    }
    set<char> ans;
    int len, width;
    auto hasRectangle = [&](char c){
        len = 20, width = 20;
        if(freq[c] == 0)
            return 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                for(int l = 0; l < n-i; l++){
                    for(int w = 0; w < n-j; w++){
                        int cnt = 0, valid = 1;
                        for(int a = 0; a <= l; a++){
                            for(int b = 0; b <= w; b++){
                                if(g[i+a][j+b] == c)
                                    cnt++;
                                else if(g[i+a][j+b] != 'x')
                                    valid = 0;
                            }
                        }
                        if(cnt == freq[c] && valid){
                            if((l+1)*(w+1) < len*width){
                                len = l+1, width = w+1;
                            }
                        }
                    }
                }
            }
        }
        if(len == 20)
            return 0;
        return 1;
    };
    priority_queue<pair<int, char>, vector<pair<int, char>>, greater<pair<int, char>>> pq;
    for(char i = '1'; i <= '9'; i++){
        if(hasRectangle(i)){
            pq.push({len*width, i});
        }
    }
    set<char> used;
    while(pq.size()){
        char color = pq.top().second;
        pq.pop();
        used.insert(color);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(g[i][j] == color)
                    g[i][j] = 'x';
            }
        }
        bool flag = 1;
        for(char i = '1'; i <= '9'; i++){
            if(hasRectangle(i) && !used.count(color)){
                flag = 0;
                pq.push({len*width, i});
            }
        }
        if(flag)
            ans.insert(color);
    }
    cout<<ans.size()<<endl;  
    return 0;
}