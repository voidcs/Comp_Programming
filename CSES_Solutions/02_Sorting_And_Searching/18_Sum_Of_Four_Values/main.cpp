#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n, x;
    scanf("%d%d", &n, &x);
    array<int, 2> a[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i][0]);
        a[i][1] = i;
    }
    
    sort(a, a + n);
    unordered_map<string, array<int, 2>> m;
    //makes unordered_map a little faster but not necessary
    //m.reserve(1<<20);
    
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            int sum = a[i][0]+a[j][0];
            string str = to_string(sum);
            m[str] = {a[i][1], a[j][1]};
        }
    }
    
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            int sum = a[i][0] + a[j][0];
            string str = to_string(x - sum);
            if(m.find(str) != m.end()){
                if(a[i][1] != m[str][0] && a[i][1] != m[str][1]){
                    if(a[j][1] != m[str][0] && a[j][1] != m[str][1]){
                        printf("%d %d %d %d\n", a[i][1]+1, a[j][1]+1, m[str][0]+1, m[str][1]+1);
                        return 0;
                    }
                }
            }
        }
    }
    printf("IMPOSSIBLE\n");
    
    return 0;
}