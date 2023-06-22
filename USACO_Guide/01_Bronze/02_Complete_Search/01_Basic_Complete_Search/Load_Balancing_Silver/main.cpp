#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    freopen("balancing.in", "r", stdin);
    freopen("balancing.out", "w", stdout);
    int n;
    cin>>n;
    vector<array<int, 2>> v(n);
    for(int i = 0; i < n; i++)
        cin>>v[i][0]>>v[i][1];
    sort(v.begin(), v.end());
    vector<array<int, 2>> sortedByY = v;
    sort(sortedByY.begin(), sortedByY.end(), [](array<int, 2> a, array<int, 2> b){
       return a[1] < b[1]; 
    });
    
    int ans = 1e9;
    int i = 0;
    int top = 0, bottom = 0;
    for(int a = 0; a < n; a++){
        int y = sortedByY[a][1] + 1;
        while(i < n && sortedByY[i][1] < y){
            bottom++;
            i++;
        }
        top = n - bottom;
        int j = 0;
        //Represents number of cows in quadrants 1 through 4
        vector<int> quadrant(5);
        for(int b = 0; b < n; b++){
            int x = v[b][0] + 1;
            while(j < n && v[j][0] < x){
                if(v[j][1] > y)
                    quadrant[2]++;
                else
                    quadrant[3]++;
                j++;
            }
            quadrant[1] = top - quadrant[2];
            quadrant[4] = bottom - quadrant[3];
            int M = 0;
            for(int q = 1; q <= 4; q++)
                M = max(M, quadrant[q]);
            ans = min(ans, M);
        }
    }
    cout<<ans<<endl;
    
    return 0;
}