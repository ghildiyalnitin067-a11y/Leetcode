class Solution {
public:
    int reversePairs(vector<int>& a) {
        int ans = 0;  
        int n = a.size(); 
        vector<long long> v;  
       
        for (int i = n - 1; i >= 0; i--) {
          
            ans += lower_bound(v.begin(), v.end(), a[i]) - v.begin();

           
            v.insert(lower_bound(v.begin(), v.end(), 2LL * a[i]), 2LL * a[i]);
        }

        return ans; 
    }
};