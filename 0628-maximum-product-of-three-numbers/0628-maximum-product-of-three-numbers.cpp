class Solution {
public:
    int maximumProduct(vector<int>& nums) {

        int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
        int min1 = INT_MAX, min2 = INT_MAX;

        for (int ele : nums) {

            if (ele >= max1) {
                max3 = max2;
                max2 = max1;
                max1 = ele;
            }
            else if (ele >= max2) {
                max3 = max2;
                max2 = ele;
            }
            else if (ele >= max3) {
                max3 = ele;
            }

            if (ele <= min1) {
                min2 = min1;
                min1 = ele;
            }
            else if (ele <= min2) {
                min2 = ele;
            }
        }

        return max(max1 * max2 * max3,
                   min1 * min2 * max1);
    }
};