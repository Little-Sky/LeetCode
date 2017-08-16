// O(res number)
// Faster than: 1.3% [Facepalm]

/*
  A faster approach is to use a index for the digits string, and not substr() all the time
*/

class Solution {
public:
    static const string key [9];    
    
    void build (vector<string> & res, const string & digits, string cur){
        if (!digits.length()) {
            if (cur.length()){
                res.push_back(cur);
            }
            return;
        }
        int digit = digits[0] - '2';
        cur += " ";
        for (int i=0; i<key[digit].length(); i++){
            cur[cur.length()-1] = key[digit][i];
            build(res, digits.substr(1), cur);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        build(res, digits, "");
        return res;
    }
};

const string Solution::key[9] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
