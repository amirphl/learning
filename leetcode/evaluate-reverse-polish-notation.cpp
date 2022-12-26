// https://leetcode.com/problems/evaluate-reverse-polish-notation/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int i = tokens.size() - 1;
        return evalRec(tokens, i);
    }

    bool is_operator(string s) {
        return s == "-" || s == "+" || s == "*" || s == "/";
    }

    int compute(int a, int b, string opt) {
        if (opt == "-") {
            return a - b;
        } else if (opt == "+") {
            return a + b;
        } else if (opt == "*") {
            return a * b;
        } else {
            return a / b;
        }
    }

    int evalRec(vector<string>& tokens, int& i) {
        if (is_operator(tokens[i])) {
            string opt = tokens[i];
            i--;
            int b = evalRec(tokens, i);
            int a = evalRec(tokens, i);

            return compute(a, b, opt);
        }

        i--;
        return stoi(tokens[i + 1]);
    }
};
