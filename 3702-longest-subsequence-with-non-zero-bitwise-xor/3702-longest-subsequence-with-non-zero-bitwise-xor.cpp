class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int total = 0;
        bool hasNonzero = false;
        
        for (int x : nums) {
            total ^= x;
            if (x != 0) hasNonzero = true;
        }
        
        if (total != 0) return nums.size();
        return hasNonzero ? (int)nums.size() - 1 : 0;
    }
};