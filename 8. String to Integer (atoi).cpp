// O(n) not using long long
// Faster than: 20% - 40%

class Solution {
public:
    int myAtoi(string str) {
        int res = 0, i = 0;
        bool isNegative = false;
        bool isOverflow = false;
        bool isEdgeCase = false;    // -2147483648
        while (i<str.length() && isspace(str[i])){
            i++;
        }
        if (str[i] == '-'){
            isNegative = true;
            i++;
        } else if (str[i] == '+'){
            i++;
        }
        while (i<str.length() && str[i] == '0'){
            i++;
        }
        for (; i<str.length() && isdigit(str[i]); i++){
            if (isEdgeCase){
                isOverflow = true;
                break;
            }
            if (res > INT_MAX / 10 || (res == INT_MAX/10 && str[i] - '0' > INT_MAX%10)){
                if (isNegative && res == INT_MAX/10 && str[i] - '0' == INT_MAX%10 + 1){
                    isEdgeCase = true;
                } else {
                   isOverflow = true;
                    break;
                }
            }
            res *= 10;
            res += str[i] - '0';
        }
        if (isOverflow){
            return isNegative ? INT_MIN : INT_MAX;
        }else{
            if (isEdgeCase){
                return INT_MIN;
            }
            return res * (isNegative  ? -1 : 1);
        }
    }
};
