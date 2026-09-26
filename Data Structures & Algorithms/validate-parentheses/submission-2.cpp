using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> brStack;
        for (char br : s) {
            if (br == '(' || br == '{' || br == '[') {
                if (br == '(') brStack.push(')');
                else if (br == '{') brStack.push('}');
                else brStack.push(']');
            }
            else {
                if (brStack.empty() || br != brStack.top()) {
                    return false;
                }
                brStack.pop();
            }
        }
        return brStack.empty();
    }
};

