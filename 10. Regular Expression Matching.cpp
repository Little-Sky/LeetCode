// O(nm)
// Faster than 66% - 88%

/*
  Used some dirty hack when dealing with the boundary (i < s.length() yet j < p.length()-1).
  The problem came as compre "a" to "ab*", where check[i-1][j-1] is not working.
*/

class Solution {
public:
    bool isMatch(string s, string p) {
        s = "^" + s + "$";
        p = "^" + p + "$";
        vector<vector<bool>> match(s.length(), vector<bool>(p.length(), false));
        match[0][0] = true;
        for (int i=1; i<s.length(); i++) {
            for (int j=1; j<p.length()-1; j++) {
                if (match[i-1][j-1]){
                    if (!match[i][j] && (p[j] == '.' || s[i] == p[j])){
                        if (p[j+1] == '*'){
                            int i2 = i;
                            while (i2 < s.length() - 1 && (p[j] == '.' || p[j] == s[i2]) ) { 
                                match[i2][j+1] = true;
                                i2++;
                            }
                        }else{
                            match[i][j] = true;
                        }
                    }
                    if (p[j+1] == '*'){
                        match[i-1][j+1] = true;
                    }
                }
            }
        }
        return match[s.length()-2][p.length()-2];
    }
};
