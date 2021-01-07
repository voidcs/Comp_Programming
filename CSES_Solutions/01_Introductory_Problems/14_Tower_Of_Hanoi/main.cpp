#include <bits/stdc++.h>
using namespace std;
 
void solve(int n, int from, int to, int aux_rod) { 
    if(n == 1){ 
        cout<<from<<" "<<to<<endl;
        return; 
    } 
    solve(n-1, from, aux_rod, to); 
    cout<<from<<" "<<to<<endl;
    solve(n-1, aux_rod, to, from); 
} 
 
int main() { 
    int n;
    cin>>n;
    cout<<(1<<n)-1<<endl;
    solve(n, 1, 3, 2);
    return 0; 
} 