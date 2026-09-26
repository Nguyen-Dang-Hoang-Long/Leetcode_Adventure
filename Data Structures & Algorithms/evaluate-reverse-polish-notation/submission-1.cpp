using namespace std;
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> calc;
        for (string token: tokens) {
            if (token.size() > 1 || (token[0] >= '0' && token[0] <= '9')) {
                int num = stoi(token);
                calc.push(num);
            }
            else {
                int num2 = calc.top();
                calc.pop();
                int num1 = calc.top();
                calc.pop();

                int res;
                if (token[0] == '+' ) res = num1 + num2;
                else if (token[0] == '-') res = num1 - num2;
                else if (token[0] == '*') res = num1 * num2;
                else res = num1 / num2;

                calc.push(res);
            } 
        }
        return calc.top();
    }
};
