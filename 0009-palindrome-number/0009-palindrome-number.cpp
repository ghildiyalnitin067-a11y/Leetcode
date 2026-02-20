class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        string rev = "";

        for(int i = s.length() - 1; i >= 0; i--){
            rev += s[i];
        }

        return s == rev;
    }
};