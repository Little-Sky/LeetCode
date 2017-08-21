// O(n) a quite slow O(n), for continuous substr operations
// Faster than 9% - 9%

class Solution {
public:
    string simplifyPath(string path) {
        if (!path.length() || path[0] != '/') {
            return "/";
        }
        stack<string> pwd;
        path = path.substr(1) + "/";
        int pos = path.find('/');
        do {
            string cur = path.substr(0, pos);
            // cout << "cur "  << pos << " " << cur  << " " << path << endl;
            path = path.substr(min(pos+1, (int)path.length()));
            pos = path.find('/');
            if (cur == "." || cur == "") {
                continue;
            } else if (cur == "..") {
                if (pwd.size() > 0) {
                    pwd.pop();
                }
            } else {
                pwd.push(cur);
            }
        } while (pos != string::npos);
            
        if (path.length()) {
            pwd.push(path);
        }
        string res = "";
        while (!pwd.empty()) {
            // cout << pwd.top() << endl;
            res = "/" + pwd.top() + res;
            pwd.pop();
        }
        return res == "" ? "/" : res;
    }
};
