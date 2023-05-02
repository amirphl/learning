// https://leetcode.com/problems/integer-to-roman/

class Solution {
public:
    string intToRoman(int num) {
        string s = "";

        if (num >= 1000) {
            int x = num / 1000;
            while(x > 0) {
                s += "M";
                x--;
            }
            num = num % 1000;
        }

        if (num >= 100) {
            if (num < 400) {
                int x = num / 100;
                while(x > 0) {
                    s += "C";
                    x--;
                }
            } else if (num < 500) {
                s += "CD";
            } else if (num < 900) {
                s += "D";
                num -= 500;
                int x = num / 100;
                while(x > 0) {
                    s += "C";
                    x--;
                }
            } else {
                s += "CM";
            }            

            num = num % 100;
        }

        if (num >= 10) {
            if (num < 40) {
                int x = num / 10;
                while(x > 0) {
                    s += "X";
                    x--;
                }
            } else if (num < 50) {
                s += "XL";
            } else if (num < 90) {
                s += "L";
                num -= 50;
                int x = num / 10;
                while(x > 0) {
                    s += "X";
                    x--;
                }
            } else {
                s += "XC";
            }
            num = num % 10;
        }
        if (num >= 0) {
            if (num < 4) {
                int x = num / 1;
                while(x > 0) {
                    s += "I";
                    x--;
                }
            } else if (num == 4) {
                s += "IV";
            } else if (num < 9) {
                s += "V";
                num -= 5;
                int x = num / 1;
                while(x > 0) {
                    s += "I";
                    x--;
                }
            } else {
                s += "IX";
            }
            // num = num % 0;
        }

        return s;
    }
};
