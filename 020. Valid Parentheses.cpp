// O(n) one iteration
// Faster than: 13%

class Solution {
public:
    bool match(char c1, char c2) {
        return (c1 == '(' && c2 == ')') || (c1 == '[' && c2 == ']') || (c1 == '{' && c2 == '}');
    }
    
    bool isValid(string s) {
        stack<char> S;
        for (int i=0; i<s.length(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                S.push(s[i]);
            } else if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
                if (S.empty() || !match(S.top(), s[i])){
                    return false;
                }
                S.pop();
            }
        }
        return S.empty();
    }
};
