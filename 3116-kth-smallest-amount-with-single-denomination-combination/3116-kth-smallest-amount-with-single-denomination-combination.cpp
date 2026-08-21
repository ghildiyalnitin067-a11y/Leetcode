class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();
        int total = 1 << n;
        
        vector<long long> subsetLcm(total, 0);
        for (int mask = 1; mask < total; mask++) {
            long long l = 1;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    long long c = coins[i];
                    long long g = __gcd(l, c);
                    l = l / g * c;
                  
                    if (l > (long long)2e18) {
                        l = (long long)2e18;
                    }
                }
            }
            subsetLcm[mask] = l;
        }
        
        auto countLE = [&](long long x) -> long long {
            long long total_count = 0;
            for (int mask = 1; mask < total; mask++) {
                long long l = subsetLcm[mask];
                int bits = __builtin_popcount(mask);
                long long term = x / l;
                if (bits % 2 == 1) {
                    total_count += term;
                } else {
                    total_count -= term;
                }
            }
            return total_count;
        };
        
        int minCoin = *min_element(coins.begin(), coins.end());
        long long lo = 1, hi = (long long)k * minCoin;
        
        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            if (countLE(mid) >= k) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        
        return lo;
    }
};