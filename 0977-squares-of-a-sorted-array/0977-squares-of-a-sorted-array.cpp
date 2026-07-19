class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans(nums.size());
       
        int i=nums.size()-1;
        int left=0;
        int right = nums.size()-1;

        while(left <= right){
            int leftsquare = nums[left]*nums[left];
            int rightsquare = nums[right]*nums[right];

            if(rightsquare < leftsquare){
                ans[i] = leftsquare;
                left++;

            }else{
                ans[i] = rightsquare;
                right--;
            }
            i--;
        }
        return ans;

    }
};