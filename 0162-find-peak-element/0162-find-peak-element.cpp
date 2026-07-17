class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0;
        int h = nums.size()-1;
        int i=0;
        int n = nums.size();

        while (l < h) {
            int m = l + (h - l) / 2;

            if (nums[m] < nums[m + 1])
                l = m + 1;
            else
                h = m;
        }

        return l;
    }
};