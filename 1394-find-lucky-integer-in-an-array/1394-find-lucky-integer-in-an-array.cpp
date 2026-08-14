class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> freq;

        for (int num : arr) {
            freq[num]++;
        }

        int element = -1;

        for (auto it : freq) {
            if (it.first == it.second) {
                element = max(element, it.first);
            }
        }

        return element;
    }
};