using namespace std;
class MinStack {
    stack<int> mainSt;
    stack<int> minSt;
public:
    MinStack() = default;
    
    void push(int val) {
        mainSt.push(val);
        if (!minSt.empty()) minSt.push(min<int>(val, minSt.top()));
        else minSt.push(val);
    }
    
    void pop() {
        mainSt.pop();
        minSt.pop();
    }
    
    int top() {
        return mainSt.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};