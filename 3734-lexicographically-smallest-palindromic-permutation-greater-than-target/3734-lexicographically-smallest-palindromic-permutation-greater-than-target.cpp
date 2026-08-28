class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        vector<int> cnt(26, 0);
        for (char c : s) cnt[c - 'a']++;
        
        int oddCount = 0, oddChar = -1;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2 == 1) {
                oddCount++;
                oddChar = i;
            }
        }
        if (oddCount > 1) return "";
        
        int half = n / 2;
        vector<int> halfCnt(26);
        for (int i = 0; i < 26; i++) halfCnt[i] = cnt[i] / 2;
        
        string targetHalf = target.substr(0, half);
        
        vector<int> temp = halfCnt;
        bool canMatch = true;
        for (int i = 0; i < half; i++) {
            int c = targetHalf[i] - 'a';
            if (temp[c] > 0) {
                temp[c]--;
            } else {
                canMatch = false;
                break;
            }
        }
        
        if (canMatch) {
            string left = targetHalf;
            string res = left;
            if (n % 2 == 1) res += char('a' + oddChar);
            string right = left;
            reverse(right.begin(), right.end());
            res += right;
            if (res > target) {
                return res;
            }
        }
        
        for (int i = half - 1; i >= 0; i--) {
            vector<int> tempCnt = halfCnt;
            bool prefixOk = true;
            for (int j = 0; j < i; j++) {
                int c = targetHalf[j] - 'a';
                if (tempCnt[c] > 0) {
                    tempCnt[c]--;
                } else {
                    prefixOk = false;
                    break;
                }
            }
            if (!prefixOk) continue;
            
            int targetChar = targetHalf[i] - 'a';
            int chosen = -1;
            for (int c = targetChar + 1; c < 26; c++) {
                if (tempCnt[c] > 0) {
                    chosen = c;
                    break;
                }
            }
            if (chosen == -1) continue;
            
            tempCnt[chosen]--;
            
            string left = targetHalf.substr(0, i);
            left += char('a' + chosen);
            
            bool fillOk = true;
            for (int pos = i + 1; pos < half; pos++) {
                int found = -1;
                for (int c = 0; c < 26; c++) {
                    if (tempCnt[c] > 0) {
                        found = c;
                        break;
                    }
                }
                if (found == -1) {
                    fillOk = false;
                    break;
                }
                tempCnt[found]--;
                left += char('a' + found);
            }
            
            if (!fillOk) continue;
            
            string res = left;
            if (n % 2 == 1) res += char('a' + oddChar);
            string right = left;
            reverse(right.begin(), right.end());
            res += right;
            
            if (res > target) {
                return res;
            }
        }
        
        return "";
    }
};