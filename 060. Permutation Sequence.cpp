// O(n) digit dp
// Faster than 57% - 57%

class Solution {
public:
    string getPermutation(int n, int k) {
        k--;
        set<int> remainNums;
        long long mod = 1;
        for (int i=1; i<=n; i++) {
            remainNums.insert(i);
            mod *= i;
        }
        string res = "";
        for (int i=n; i>=1; i--){
            mod /= i;
            int order = k / mod;
            k %= mod;
            auto itr = remainNums.begin();
            advance(itr, order);
            res += *itr + '0';
            remainNums.erase(itr);
        }
        return res;
    }
};
