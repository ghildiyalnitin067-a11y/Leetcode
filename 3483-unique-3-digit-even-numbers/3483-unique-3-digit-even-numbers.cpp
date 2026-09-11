class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int freq[10] = {};
        for (int x : digits)
            freq[x]++;

        int ans = 0;

        for (int last = 0; last <= 8; last += 2) {
            if (!freq[last]) continue;

            freq[last]--;

            
            for (int mid = 0; mid < 10; mid++) {
                if (!freq[mid]) continue;

                freq[mid]--;

                
                for (int first = 1; first <= 9; first++)
                    if (freq[first])
                        ans += 1;

                freq[mid]++;
            }

            freq[last]++;
        }

        return ans;
    }
};