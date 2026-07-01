class Solution {
public:
    int singleNumber(vector<int>& nums) {

        for(int i = 0; i < nums.size(); i++) {

            int result = 0;
            int num = nums[i];

            for(int j = 0; j < nums.size(); j++) {

                if(nums[j] == num) {
                    result++;
                }

            }

            if(result == 1) {
                return num;
            }

        }

        return -1;
    }
};