class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        unordered_map<int,int> f;
        
        for(int x:nums){
            f[x]++;
        }

        for(int x:nums){
            if(x%2 ==0 && f[x]==1){
                return x;
            }
        }
        return -1;
    }
};