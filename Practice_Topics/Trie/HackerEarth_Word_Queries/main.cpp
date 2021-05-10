#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

//PROBLEM LINK
//https://www.hackerearth.com/practice/data-structures/advanced-data-structures/trie-keyword-tree/practice-problems/algorithm/dummy4-2/

struct Node{
    int cnt;
    vector<int> next;
    Node(){
        cnt = 0;
        next = vector<int>(26, -1);
    }
};

int main(){
    //freopen("input.txt", "r", stdin);
    int n, q;
    cin>>n>>q;
    vector<Node> trie;
    trie.push_back(Node());
    auto add = [&](string s){
        int i = 0;
        for(char c: s){
            int j = c - 'a';
            if(trie[i].next[j] == -1){
                trie[i].next[j] = trie.size();
                trie.push_back(Node());
            }
            i = trie[i].next[j];
            trie[i].cnt++;
        }
    };
    
    auto query = [&](string s){
        int i = 0;
        for(char c: s){
            int j = c - 'a';
            if(trie[i].next[j] == -1){
                return 0;
            }
            i = trie[i].next[j];
        }
        return trie[i].cnt;
    };
    
    for(int i = 0; i < n; i++){
        string s;
        cin>>s;
        add(s);
    }
    
    while(q--){
        string s;
        cin>>s;
        cout<<query(s)<<endl;
    }
    return 0;
}