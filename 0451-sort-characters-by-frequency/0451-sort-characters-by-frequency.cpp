class Solution {
public:
    string frequencySort(string s) {
        int freq[128] = {0};

        for (char c : s) {
            freq[c]++;
        }

        string result = "";

        for (int count = s.size(); count >= 1; count--) {
            for (int c = 0; c < 128; c++) {
                if (freq[c] == count) {
                    for (int k = 0; k < count; k++) {
                        result += (char)c;
                    }
                }
            }
        }

        return result;
    }
};