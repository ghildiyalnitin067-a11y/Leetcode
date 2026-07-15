class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumeven = n*n + n;
        int sumodd = n*n;
        return gcd(sumeven , sumodd);
    }
};