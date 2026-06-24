class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max_streak = 0;
        int current_streak = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
               
                current_streak++;
            } else {
               
                if (current_streak > max_streak) {
                    max_streak = current_streak;
                }
                
                current_streak = 0;
            }
        }

       
        if (current_streak > max_streak) {
            max_streak = current_streak;
        }

        return max_streak;
    }
};