class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
      
        vector<int> firstIndex(2 * n + 1, -2); 
        firstIndex[n] = -1; 
        
        int count = 0;
        int maxLen = 0;
        
        for (int i = 0; i < n; i++) {
            count += (nums[i] == 1) ? 1 : -1;
            int idx = count + n; 
            
            if (firstIndex[idx] != -2) {
                maxLen = max(maxLen, i - firstIndex[idx]);
            } else {
                firstIndex[idx] = i;
            }
        }
        
        return maxLen;
    }
};