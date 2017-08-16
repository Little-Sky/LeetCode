// O(1) 
// Faster than 36% - 71%

/*
  A faster method: hardcode all digits (1-9)
  Divides by 1000, 100, 10, 1 and add together.
*/

class Solution {
public:
    void appendMultiple (string & str, string ch, int times){
        for (int i=0; i<times; i++){
            str += ch;
        }
    }

//  Roman integer:
//            I	V	X	L	C	D	M
//    Value	1	5	10	50	100	500	1,000
//    1,2,3: repeat; 4: minus
//  const int[] integer = [1, 5, 10, 50, 100, 500, 1000, 0];
    

    string intToRoman(int num) {
        const string roman[] = {"I", "V", "X", "L", "C", "D", "M"};
        int digit = (int) log10(num);
        string res = "";
        while (num > 0){
            int mod = (int)pow(10, digit);
            int lead_digit = num / mod;
            int index = digit * 2;
            
            if (lead_digit == 4){
                res += roman[index] + roman[index+1];
            } else if (lead_digit == 9){
                res += roman[index] + roman[index+2];
            } else {
                if (lead_digit >= 5){
                    res += roman[index+1];
                    lead_digit -= 5;
                }
                appendMultiple (res, roman[index], lead_digit);
            }
            num %= mod;
            digit--;
        }
        return res;
    }
};
