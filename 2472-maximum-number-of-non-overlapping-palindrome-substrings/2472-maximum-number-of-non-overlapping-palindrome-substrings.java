class Solution {
    public int maxPalindromes(String s, int k) {
        int n = s.length(), ans = 0, last = -1;
        boolean[][] p = new boolean[n][n];

        for (int i = n - 1; i >= 0; i--)
            for (int j = i; j < n; j++)
                p[i][j] = s.charAt(i) == s.charAt(j) &&
                          (j - i < 2 || p[i + 1][j - 1]);

        for (int r = 0; r < n; r++) {
            for (int l = last + 1; l <= r - k + 1; l++) {
                if (p[l][r]) {
                    ans++;
                    last = r;
                    break;
                }
            }
        }
        return ans;
    }
}