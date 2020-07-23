#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
 * Purpose is to see if a target sum can be achieved using any set of numbers
 * from an array using dynamic programming
 * 
 * Reference video: https://www.youtube.com/watch?v=HjJI1tbtn_M&list=PL2q4fbVm1Ik4ktv2_1O1atXoeV7whMAy_&index=11
*/

int main(){
    cout<<"Enter the size of the array and the desired sum: \n";
    ll n, goal;
    scanf("%lld%lld", &n, &goal);
    
    ll a[n];
    for(int i = 0; i < n; i++)
        scanf("%lld", a + i);
    
    ll dp[goal+1];
    for(int i = 0; i <= goal; i++)
        dp[i] = 0;
    dp[0] = 1;
    
    for(int i = 0; i < n; i++){
        for(int j = goal; j >= a[i]; j--){
            if(dp[j] || dp[j-a[i]] == 0)
                continue;
            
            if(dp[j-a[i]])
                dp[j] = a[i];
        }
    }
    
    printf("\nTop row represents a target sum\nBottom row states if it is possible to reach the sum\n");
    for(int i = 0; i <= goal; i++)
        printf("%3d ", i);
    printf("\n");
    
    for(int i = 0; i <= goal; i++)
        printf("%3lld ", dp[i]);
    printf("\n\n");
    
    if(dp[goal] == 0)
        printf("Cannot reach target sum\n");
    else{
        printf("Possible to reach sum %lld using: ", goal);
        ll curr = goal;
        while(curr > 0){
            printf("%lld ", dp[curr]);
            curr -= dp[curr];
        }
        printf("\n");
    }
    return 0;
}