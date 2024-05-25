class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        typedef long long ll;
        ll m = 100019;
        ll p = 31;
        ll x = 1;

        vector<ll> prefix = {0};
        ll sum = 0;
        for(char c: s){
            sum += (c - 'a' + 1) * x;
            sum %= m;
            prefix.push_back(sum);
            x = (x * p) % m;
        }
        auto expo_power = [&](ll base, ll power){
            ll res = 1;
            while(power){
                if(power % 2){
                    res = (res * base) % m;
                }
                base = (base * base) % m;
                power /= 2;
            }
            return res;
        };
        vector<ll> precomputed;
        for(int i = 0; i <= s.length(); i++){
            precomputed.push_back(expo_power(expo_power(p, i), m-2) % m);
        }
        function<ll(int, int)> hash = [&](int l, int r){
            ll res = (prefix[r+1] - prefix[l] + m) % m;
            //Divide by p ^ l
            //Multiply by inverse of p ^ l mod m
            res = (res * precomputed[l]) % m;
            return res;
        };

        auto calc_hash = [&](string s){
            ll x = 1;
            ll res = 0;
            for(char c: s){
                res += (c - 'a' + 1) * x;
                res %= m;
                x = (x * p) % m;
            }
            return res;
        };

        vector<string> look_up(m);
        for(string s: wordDict){
            look_up[calc_hash(s)] = s;
        }
        vector<string> ans;
        int n = s.length();
        vector<string> v;
        function<void(int)> f = [&](int i){
            if(i == n){
                string res;
                for(int i = 0; i < v.size(); i++){
                    res += v[i];
                    if(i+1 != v.size()){
                        res += " ";
                    }
                }
                ans.push_back(res);
                return;
            }
            for(int d = 1; d <= n-i; d++){
                int x = hash(i, i+d-1);
                if(look_up[x] != ""){
                    v.push_back(look_up[x]);
                    f(i+d);
                    v.pop_back();
                }
            }
        };
        f(0);
        return ans;
    }
};