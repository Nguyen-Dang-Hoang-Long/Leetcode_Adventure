
using namespace std;
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // Res vec
        vector<int> res(temperatures.size(), 0);
        // Stack
        stack<int> indices;
        // Run thru the vec
        for (int i = 0; i < temperatures.size(); i++) {
            while (!indices.empty() && temperatures[i] > temperatures[indices.top()]) {
                res[indices.top()] = i - indices.top();
                indices.pop();
            }
            indices.push(i);
        }
        return res;
    }
};