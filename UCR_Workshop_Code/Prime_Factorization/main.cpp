#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int temp = n;
    //Brute Force ish way
    for(int i = 2; i <= n; i++){
        int cnt = 0;
        while(n%i == 0){
            n /= i;
            cnt++;
        }
        if(cnt > 0)
            cout<<i<<" to the power of "<<cnt<<endl;
    }
    
    cout<<endl;
    n = temp;
    //Faster way
    for(int i = 2; i <= sqrt(n); i++){
        int cnt = 0;
        while(n%i == 0){
            n /= i;
            cnt++;
        }
        if(cnt > 0)
            cout<<i<<" to the power of "<<cnt<<endl;
    }
    if(n > 1)
        cout<<n<<" to the power of 1"<<endl;
    return 0;
}
