// Manacher's algorithm: 
//   find the longest palindromic substring
// O(n) two iterations

// "abc" -> "^#a#b#c$", where '^' and '$' are sentinels appended to avoid boundary checkings.
string precompute (const string & s) {
    string res = "^";
    for (int i=0; i<s.length(); i++) {
        res += "#" + s.substr(i, 1);     // Don't mix string with char
    }
    res += "#$";
    return res;
}

string longestPalindrome (string & s) {
    // Center, rightmost palindrome ending.
    int C=0, R=0;
    string T = precompute(s);
    vector<int> res (T.length(), 0);
    // From '^' to '$'
    for (int i=1; i<T.length()-1; i++){
        int i_mirror = 2*C - i;  // Reflected point around C
        res[i] = R > i ? min(R-i, res[i_mirror]) : 0;
        while (T[i + res[i] + 1] == T[i - res[i] -1]) {
            res[i]++;
        }
        if (i + res[i] > R){     // Extends the ending
            R = i + res[i];
            C = i;
        }
    }
    int center_index = 0, max_len = 0;
    for (int i=1; i<T.length()-1; i++){
        if (res[i] > max_len){
            max_len = res[i];
            center_index = i;
        }
    }
    return s.substr((center_index - max_len - 1)/2, max_len);
}
