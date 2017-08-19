// O(n^2) digit dp; list version.
// Faster than 57% - 57%

class Solution {
public:
    string getPermutation(int n, int k) {
        k--;
        list<int> remainNums;
        long long mod = 1;
        for (int i=1; i<=n; i++) {
            remainNums.push_back(i);
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
    
// O(n^2 log n) digit dp; Set version, erase should be slower.
// Faster than 57% - 57%
    
    // string getPermutation(int n, int k) {
    //     k--;
    //     set<int> remainNums;
    //     long long mod = 1;
    //     for (int i=1; i<=n; i++) {
    //         remainNums.insert(i);
    //         mod *= i;
    //     }
    //     string res = "";
    //     for (int i=n; i>=1; i--){
    //         mod /= i;
    //         int order = k / mod;
    //         k %= mod;
    //         auto itr = remainNums.begin();
    //         advance(itr, order);
    //         res += *itr + '0';
    //         remainNums.erase(itr);
    //     }
    //     return res;
    // }
};
