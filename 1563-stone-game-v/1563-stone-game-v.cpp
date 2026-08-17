class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();

        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + stoneValue[i];
        }

    
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int len = 2; len <= n; len++) {
            for (int left = 0; left + len <= n; left++) {

                int right = left + len - 1;

                for (int mid = left; mid < right; mid++) {

                    int leftSum = prefix[mid + 1] - prefix[left];
                    int rightSum = prefix[right + 1] - prefix[mid + 1];

                    if (leftSum < rightSum) {
                        dp[left][right] =
                            max(dp[left][right],
                                leftSum + dp[left][mid]);
                    }
                    else if (leftSum > rightSum) {
                        dp[left][right] =
                            max(dp[left][right],
                                rightSum + dp[mid + 1][right]);
                    }
                    else {
                        dp[left][right] =
                            max(dp[left][right],
                                max(leftSum + dp[left][mid],
                                    rightSum + dp[mid + 1][right]));
                    }
                }
            }
        }

        return dp[0][n - 1];
    }
};