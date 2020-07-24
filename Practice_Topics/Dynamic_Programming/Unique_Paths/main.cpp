#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//REFERENCE VIDEO
//https://www.youtube.com/watch?v=WvfCbcUjBds&list=PL2q4fbVm1Ik4ktv2_1O1atXoeV7whMAy_&index=19

/*
 * Goal is to see how many unique paths exist from top left most cell (0,0)
 * to the bottom right most cell (n-1, m-1)
*/

int main(){
    
    printf("Enter the row and col sizes\n");
    ll n, m;
    scanf("%lld%lld", &n, &m);
    
    ll a[n][m];
    
    //Initialize last row to 1
    for(int i = 0; i < m; i++)
        a[n-1][i] = 1;
    
    //Initialize last col to 1
    for(int i = 0; i < n; i++)
        a[i][m-1] = 1;
    
    //Start from second lowest row, iterate from right to left
    //Number of paths for a[i][j]th cell is sum of cell below + cell to the right
    for(int i = n-2; i >= 0; i--){
        for(int j = m-2; j >= 0; j--){
            a[i][j] = a[i+1][j] + a[i][j+1];
        }
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("%4lld ", a[i][j]);
        }
        printf("\n");
    }
    
    printf("\nThe total number of paths is: %lld", a[0][0]);
    
    return 0;
}