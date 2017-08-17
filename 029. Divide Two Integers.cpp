// O(log divident/divisor)
// Faster than 65% - 91%


class Solution {
public:
    int divide(long long dividend, long long divisor) {
        if (divisor == 0 || (dividend == INT_MIN && divisor == -1)){
            return INT_MAX;
        }
        string res = "0";
        bool negative = (dividend < 0) ^ (divisor < 0); 
        dividend = labs (dividend);
        divisor = labs (divisor);
        // cout << dividend << endl << divisor << endl;
        int cnt = 1;
        while (dividend - divisor >= divisor) {
            divisor <<= 1;
            cnt++;
        }
        while (cnt--) {
            if (dividend >= divisor) {
                res += "1";
                dividend -= divisor;
            } else {
                res += "0";
            }
            divisor >>= 1;
        }
        // cout << res;
        return (negative ? -1 : 1) * stoll(res, nullptr, 2);
    }
};
