int solve(string s) {
    int ans = 0;
    int bal = 0;
    int ans1 = 0, ans2 = 0;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == ')')
            bal++;
        else
            bal--;
        ans1 = max(ans1, bal);
    }
    bal = 0;
    for(int i = s.length()-1; i >= 0; i--){
        if(s[i] == '(')
            bal++;
        else
            bal--;
        ans2 = max(ans2, bal);
    }
    return ans1+ans2;
}