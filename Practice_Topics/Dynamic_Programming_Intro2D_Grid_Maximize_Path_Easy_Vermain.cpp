#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
 * Find the greatest cost of a path from cell (1,1) to (N, M)
 * going only down or right
 * 
 * Reference video: https://www.youtube.com/watch?v=su3cE9RpGJk&list=PL2q4fbVm1Ik4ktv2_1O1atXoeV7whMAy_&index=12
 * 
 * Test case 1:
 * 3 4
 * 5 1 2 6
 * 9 9 7 5
 * 3 1 4 8
 * 
 * Answer: 43
*/

int main(){
    ll n, m;
    scanf("%lld%lld", &n, &m);
    ll a[n+1][m+1];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++)
            scanf("%lld", &a[i][j]);
    }
    
    ll INF = 10e10;
    //Only different is that instead of initializing row/col with INF, we use -1
    ll dp[n+2][m+2];
    for(int i = 1; i <= m+1; i++)
        dp[n+1][i] = -1;
    
    for(int i = 1; i <= n+1; i++)
        dp[i][m+1] = -1;
    
    dp[n+1][m] = 0;
    dp[n][m+1] = 0;
    
    //Take the greater of the two options instead of the lesser
    for(int i = n; i >= 1; i--){
        for(int j = m; j >= 1; j--){
            dp[i][j] = a[i][j] + max(dp[i+1][j], dp[i][j+1]);
        }
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            printf("%lld ", dp[i][j]);
        }
        printf("\n");
    }
    
    printf("Highest cost path is: %lld\n", dp[1][1]);
    
    
    
    return 0;
}
