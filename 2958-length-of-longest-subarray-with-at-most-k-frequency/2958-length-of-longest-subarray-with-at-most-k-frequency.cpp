class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
         unordered_map<int, int> freq;
        int left = 0;
        int best = 0;
        
        for (int right = 0; right < (int)nums.size(); right++) {
            int val = nums[right];
            freq[val]++;
            
           
            while (freq[val] > k) {
                freq[nums[left]]--;
                left++;
            }
            
            best = max(best, right - left + 1);
        }
        
        return best;
    }
};