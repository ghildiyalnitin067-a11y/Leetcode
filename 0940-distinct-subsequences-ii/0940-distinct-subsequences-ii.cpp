class Solution {
public:
    int distinctSubseqII(string s) {
        constexpr long long MOD = 1e9 + 7;
        
        array<long long, 26> endCount{};
        long long total = 0;

        for (char c : s) {
            int idx = c - 'a';
            long long newCount = (total + 1) % MOD;
            total = (total - endCount[idx] + newCount + MOD) % MOD;
            endCount[idx] = newCount;
        }

        return static_cast<int>(total);
    }
};