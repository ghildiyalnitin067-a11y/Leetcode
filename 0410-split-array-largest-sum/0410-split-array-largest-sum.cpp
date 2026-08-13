class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        long long lower =0, high = 0;
        for(int num : nums){
            lower = max(lower, (long long)num);
            high += num;                                                     
        }

        while(lower < high){
            long long mid = lower + ( high - lower)/2;
            if(doable(nums,k,mid)){
                high = mid;

            }else{
                lower = mid+1;
            }
        }
        return (int)lower;
    }

private:
     bool doable(vector<int>&nums,int k, long long mid){
        long long sum =0;
        int pieces = 1;

        for(int num :nums){
            sum += num;

            if(sum > mid){
                pieces++;
                sum = num;

                if(pieces >k){
                    return false;
                }
            }
        }
        return true;
     }
};