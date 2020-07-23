#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//REFERENCE VIDEO
//https://www.youtube.com/watch?v=OjaUemQyDmw&list=PL2q4fbVm1Ik4ktv2_1O1atXoeV7whMAy_&index=16

int main(){
    string str;
    cout<<"Enter a string: \n";
    cin>>str;
    ll n = str.length();
    bool dp[n+1][n+1];
    
    //Initialize everything to zero
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++)
            dp[i][j] = 0;
    }
    
    //All substrings length 0 and 1 are palindromes
    for(int i = 0; i <= n; i++)
        dp[0][i] = dp[1][i] = 1;
    
    //Start from length 2 substrings
    for(int i = 2; i <= n; i++){
        for(int j = i; j <= n; j++){
            //If the first and last character match, check if the n-2 length
            //substring is also a palindrome
            if(str[j-1] == str[j-i] && dp[i-2][j-1])
                dp[i][j] = 1;
            else
                dp[i][j] = 0;
        }
    }
    
    int ans = 0;
    
    cout<<"DP table: \n";
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            cout<<dp[i][j]<<" ";
            if(dp[i][j])
                ans = max(ans, i);
        }
        cout<<endl;
    }
    cout<<"The maximum length palindrome substring is: "<<ans<<endl;
    return 0;
}