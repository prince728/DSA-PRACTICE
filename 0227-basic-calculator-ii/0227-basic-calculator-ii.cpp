class Solution {
public:
    int calculate(string s) {
        if (s.empty()) return 0;

        vector<int> stack;
        long long current_number = 0; 
        char current_operator = '+';

        for (int i = 0; i < s.length(); ++i) {
            char current_char = s[i];

            if (isdigit(current_char)) {
                current_number = current_number * 10 + (current_char - '0');
            }

            if ((!isdigit(current_char) && !isspace(current_char)) || i == s.length() - 1) {
                if (current_operator == '+') {
                    stack.push_back(current_number);
                } else if (current_operator == '-') {
                    stack.push_back(-current_number);
                } else if (current_operator == '*') {
                    int top = stack.back();
                    stack.pop_back();
                    stack.push_back(top * current_number);
                } else if (current_operator == '/') {
                    int top = stack.back();
                    stack.pop_back();
                    stack.push_back(top / current_number);
                }
                current_operator = current_char;
                current_number = 0;
            }
        }

        int result = 0;
        for (int val : stack) {
            result += val;
        }
        return result;
    }
};
