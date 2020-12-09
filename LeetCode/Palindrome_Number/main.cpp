class Solution {
    //PROBLEM LINK
    //https://leetcode.com/problems/palindrome-number/
public:
    bool isPalindrome(int x) {
        string str = to_string(x);
        string r = str;
        reverse(r.begin(), r.end());
        return (str == r);
    }
};