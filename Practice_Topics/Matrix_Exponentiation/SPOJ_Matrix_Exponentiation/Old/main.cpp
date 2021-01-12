#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 101
#define mod 1000000007

//PROBLEM LINK
//https://www.spoj.com/problems/MPOW/
//REFERENCE VIDEO
//https://www.youtube.com/watch?v=d8xB9jgEu-A&list=PL2q4fbVm1Ik4liHX78IRslXzUr8z5QxsG&index=11

ll ar[N][N]; //Answer
ll I[N][N]; //Identity matrix
 
//Matrix multiplication
void mult(ll A[][N], ll B[][N], int dim){
    
    //Temp array to hold result
    ll res[dim+1][dim+1];
    
    for(int i = 1; i <= dim; i++){
        for(int j = 1; j <= dim; j++){
            
            res[i][j] = 0;
            for(int k = 1; k <= dim; k++){
                res[i][j] += (A[i][k] * B[k][j]) % mod;
                res[i][j] %= mod;
            }
        }
    }
    
    //Assign result array to A
    for(int i = 1; i <= dim; i++){
        for(int j = 1; j <= dim; j++){
            A[i][j] = res[i][j];
        }
    } 
}
 
void power(ll A[][N], int dim, int n){
    
    //Initialize identity matrix;
    for(int i = 1; i <= dim; i++){
        for(int j = 1; j <= dim; j++){
            if(i == j)
                I[i][j] = 1;
            else
                I[i][j] = 0;
        }
    }
    
    //Binary exponentiation
    while(n){
        if(n%2){
            mult(I, A, dim);
            n--;
        }
        else{
            mult(A, A, dim);
            n /= 2;
        }
    }
    
    //Save the answer in A
    for(int i = 1 ; i <= dim; i++){
        for(int j = 1; j <= dim; j++){
            A[i][j] = I[i][j];
        }
    }
    
}
 
void printMatrix(ll A[][N], int dim){
    for(int i = 1; i <= dim; i++){
        for(int j = 1; j <= dim; j++){
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
}
 
int main(){
    int t;
    cin>>t;
    while(t--){
        int dim, pow;
        cin>>dim>>pow;
 
        for(int i = 1; i <= dim; i++){
            for(int j = 1; j <= dim; j++)
                cin>>ar[i][j];
        }
        
        power(ar, dim, pow);
        printMatrix(ar, dim);  
    }
    return 0;
}