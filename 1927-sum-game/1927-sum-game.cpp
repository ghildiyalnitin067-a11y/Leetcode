class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int half = n / 2;
        long long s1 = 0, s2 = 0;
        int q1 = 0, q2 = 0;

        for (int i = 0; i < half; i++) {
            if (num[i] == '?') q1++;
            else s1 += num[i] - '0';
        }
        for (int i = half; i < n; i++) {
            if (num[i] == '?') q2++;
            else s2 += num[i] - '0';
        }

        int totalQ = q1 + q2;

        if (totalQ % 2 == 1) {
            return true;
        }

        
        long long forced = 2 * (s1 - s2) + 9LL * (q1 - q2);
        return forced != 0;
    }
};