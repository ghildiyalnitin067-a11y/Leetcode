class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();

        
        vector<int> cnt(26, 0);
        for (char ch : s) cnt[ch - 'a']++;

        vector<int> cur = cnt;         
        int best_i = -1, best_char = -1;
        vector<int> best_snapshot;     
        
        for (int i = 0; i < n; i++) {
            int t = target[i] - 'a';

            
            for (int c = t + 1; c < 26; c++) {
                if (cur[c] > 0) {
                    best_i = i;              
                    best_char = c;          
                    best_snapshot = cur;    
                    break;
                }
            }

           
            if (cur[t] == 0) break;  
            cur[t]--;
        }


        if (best_i == -1) return "";

        
        vector<int> finalCnt = best_snapshot;
        finalCnt[best_char]--;                    

        string result = target.substr(0, best_i);  
        result += char('a' + best_char);           

       
        for (int c = 0; c < 26; c++) {
            result += string(finalCnt[c], char('a' + c));
        }

        return result;
    }
};