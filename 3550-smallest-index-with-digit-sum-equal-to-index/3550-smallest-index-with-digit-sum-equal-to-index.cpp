class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        auto digitSum = [](long long x) {
            int s = 0;
            for (x = llabs(x); x; x /= 10) s += x % 10;
            return s;
        };
        int limit = min<int>(nums.size(), 91);
        for (int i = 0; i < limit; i++)
            if (digitSum(nums[i]) == i) return i;
        return -1;
    }
};