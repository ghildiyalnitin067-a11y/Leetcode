class Solution {
public:
    bool checkDivisibility(int n) {
        int total = 0, product = 1;
        
        for (int temp = n; temp > 0; temp /= 10) {
            int digit = temp % 10;
            total += digit;
            product *= digit;
        }
        
        return n % (total + product) == 0;
    }
};