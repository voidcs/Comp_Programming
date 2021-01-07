#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int a[1060];
unordered_map<int, array<int, 2>> m;
int n, x;
 
int main(){
    scanf("%d%d", &n, &x);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    
    m.reserve(1<<19);
    
    for(int i = 0; i < n; ++i){
        for(int j = i+1; j < n; ++j){
            if(m.find(x-a[i]-a[j]) != m.end()){
                printf("%d %d %d %d\n", i+1, j+1, m[x-a[i]-a[j]][0]+1, m[x-a[i]-a[j]][1]+1);
                return 0; 
            }
        }
        for(int j = 0; j < i; ++j)
            m[a[i]+a[j]] = {i, j};
    }
    printf("IMPOSSIBLE\n");
    
    return 0;
}