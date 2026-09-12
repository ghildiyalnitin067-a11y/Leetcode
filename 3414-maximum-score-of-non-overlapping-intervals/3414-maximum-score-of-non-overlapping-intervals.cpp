class Solution {
public:
   
    struct State {
        long long score;
        vector<int> idx;
    };
    static bool lexSmaller(const vector<int>& a, const vector<int>& b) {
        return lexicographical_compare(a.begin(), a.end(), b.begin(), b.end());
    }
    static bool better(const State& a, const State& b) {
        if (a.score != b.score) return a.score > b.score;
        return lexSmaller(a.idx, b.idx);
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> order(n);
        iota(order.begin(), order.end(), 0);

        sort(order.begin(), order.end(), [&](int a, int b) {
            return intervals[a][1] < intervals[b][1];
        });

        vector<int> rights(n);
        for (int i = 0; i < n; i++) rights[i] = intervals[order[i]][1];
        vector<vector<State>> dp(n + 1, vector<State>(5, {0, {}}));

        for (int i = 1; i <= n; i++) {
            int origIdx = order[i - 1];
            long long l = intervals[origIdx][0];
            long long w = intervals[origIdx][2];
            int j = lower_bound(rights.begin(), rights.begin() + (i - 1), l) - rights.begin();

            for (int k = 0; k <= 4; k++) {
                State best = dp[i - 1][k]; 

                if (k >= 1) {
                    State cand = dp[j][k - 1];
                    cand.score += w;
                    auto pos = upper_bound(cand.idx.begin(), cand.idx.end(), origIdx);
                    cand.idx.insert(pos, origIdx);

                    if (better(cand, best)) best = cand;
                }
                dp[i][k] = best;
            }
        }

        return dp[n][4].idx;
    }
};