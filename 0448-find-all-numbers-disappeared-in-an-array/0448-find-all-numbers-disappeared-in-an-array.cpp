class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n =nums.size();
        vector<int> ans;
        vector<int> freq (n+1,0);


        for(int num : nums){
            freq[num]++;
        }

        for(int i=1;i<=n;i++){
            if(freq[i] ==0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};