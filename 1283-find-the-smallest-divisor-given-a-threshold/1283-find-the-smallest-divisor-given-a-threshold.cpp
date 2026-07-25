class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int lo = 1, hi = *max_element(nums.begin(), nums.end());
        
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            
            if (computeSum(nums, mid) <= threshold) {
                hi = mid;      
            } else {
                lo = mid + 1;  
            }
        }
        
        return lo;
    }
    
private:

    long long computeSum(vector<int>& nums, int divisor) {
        long long sum = 0;
        for (int num : nums) {
            sum += (num + divisor - 1) / divisor;
        }
        return sum;
    }
};