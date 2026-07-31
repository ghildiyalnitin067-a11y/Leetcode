class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26, 0);

        for (char ch : word)
            freq[ch - 'a']++;

        sort(freq.begin(), freq.end(), greater<int>());

        vector<int> cost;
        for (int i = 0; i < 8; i++) cost.push_back(1);
        for (int i = 0; i < 8; i++) cost.push_back(2);
        for (int i = 0; i < 8; i++) cost.push_back(3);
        for (int i = 0; i < 2; i++) cost.push_back(4);

        int ans = 0;

        for (int i = 0; i < 26; i++) {
            ans += freq[i] * cost[i];
        }

        return ans;
    }
};