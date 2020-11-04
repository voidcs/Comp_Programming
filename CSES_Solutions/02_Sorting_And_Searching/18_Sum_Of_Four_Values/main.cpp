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
    unordered_map<int, array<int, 2>> m;
    m.reserve(1<<19);
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++)
            m[a[i][0]+a[j][0]] = {a[i][1], a[j][1]};
    }
    
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            int sum = a[i][0] + a[j][0];
            if(m.find(x - sum) != m.end()){
                if(a[i][1] != m[x-sum][0] && a[i][1] != m[x-sum][1]){
                    if(a[j][1] != m[x-sum][0] && a[j][1] != m[x-sum][1]){
                        printf("%d %d %d %d\n", a[i][1]+1, a[j][1]+1, m[x-sum][0]+1, m[x-sum][1]+1);
                        return 0;
                    }
                }
            }
        }
    }
    printf("IMPOSSIBLE\n");
    
    return 0;
}