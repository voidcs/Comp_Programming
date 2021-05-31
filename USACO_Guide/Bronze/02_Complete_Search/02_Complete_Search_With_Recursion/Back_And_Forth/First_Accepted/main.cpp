#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    freopen("backforth.in", "r", stdin);
    freopen("backforth.out", "w", stdout);
    int a = 1000;
    set<int> s;
    vector<int> x(10), y(10);
    vector<bool> visX(10), visY(10), takenX(10, 1), takenY(10, 1);
    for(int &r: x)
        cin>>r;
    for(int &r: y)
        cin>>r;
    function<void(int)> search = [&](int day){
        if(day == 4){
            s.insert(a);
            return;
        }
        if(day%2 == 0){
            for(int i = 0; i < 10; i++){
                if(!visX[i]){
                    visX[i] = 1;
                    a -= x[i];
                    takenY[i] = 0;
                    search(day+1);
                    takenY[i] = 1;
                    a += x[i];
                    visX[i] = 0;
                }
            }
            for(int i = 0; i < 10; i++){
                if(!takenX[i]){
                    takenX[i] = 1;
                    a -= y[i];
                    search(day+1);
                    a += y[i];
                    takenX[i] = 0;
                }
            }
        }
        else{
            for(int i = 0; i < 10; i++){
                if(!visY[i]){
                    visY[i] = 1;
                    takenX[i] = 0;
                    a += y[i];
                    search(day+1);
                    a -= y[i];
                    takenX[i] = 1;
                    visY[i] = 0;
                }
            }
            for(int i = 0; i < 10; i++){
                if(!takenY[i]){
                    takenY[i] = 1;
                    a += x[i];
                    search(day+1);
                    a -= x[i];
                    takenY[i] = 0;
                }
            }
        }
    };
    search(0);
    cout<<s.size()<<endl;
    
    return 0;
}