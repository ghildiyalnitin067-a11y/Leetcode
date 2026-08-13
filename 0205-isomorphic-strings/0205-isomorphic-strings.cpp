class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int checkS[256] = {};
        int checkT[256] = {};

        for (int i = 0; i < s.size(); i++) {

            if (checkS[s[i]] != checkT[t[i]])
                return false;

            checkS[s[i]] = i + 1;
            checkT[t[i]] = i + 1;
        }

        return true;
    }
};