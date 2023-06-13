#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int k;
    auto read_trash = [&](){
        string trash;
        cin>>k;
        for(int i = 0; i < k; i++)
            cin>>trash;
    };
    cout<<"next 0\n";
    cout.flush();
    read_trash();
    cout<<"next 1\n";
    cout.flush();
    read_trash();
    cout<<"next 1\n";
    cout.flush();
    read_trash();
    while(1){
        cout<<"next 0 1\n";
        cout.flush();
        read_trash();
        cout<<"next 1\n";
        cout.flush();
        read_trash();
        if(k == 2)  //This means that 0 and 1 are synced up again in the loop somewhere
            break;
    }
    //Now move everything else and (0, 1) together one step at a time. They will meet at the start of the cycle
    while(1){
        cout<<"next 0 1 2 3 4 5 6 7 8 9\n";
        cout.flush();
        read_trash();
        if(k == 1)
            break;
    }
    cout<<"done"<<endl;
}
