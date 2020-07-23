#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
 * Purpose is to see if a target sum can be achieved using any set of numbers
 * from an array using dynamic programming
 * 
 * This version only states if it is possible, does not say which numbers
 * should be used
 * 
 * Reference video: https://www.youtube.com/watch?v=-httet0UVUU&list=PL2q4fbVm1Ik4ktv2_1O1atXoeV7whMAy_&index=10
*/

int main(){
    cout<<"Enter the size of the array and the desired sum: \n";
    ll n, goal;
    scanf("%lld%lld", &n, &goal);
    
    ll a[n];
    for(int i = 0; i < n; i++)
        scanf("%lld", a + i);
    
    bool dp[goal+1];
    for(int i = 0; i <= goal; i++)
        dp[i] = 0;
    dp[0] = 1;
    
    for(int i = 0; i < n; i++){
        for(int j = goal; j >= a[i]; j--){
            if(dp[j-a[i]])
                dp[j] = 1;
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
        printf("Possible to reach %lld\n", goal);
    }
    return 0;
}