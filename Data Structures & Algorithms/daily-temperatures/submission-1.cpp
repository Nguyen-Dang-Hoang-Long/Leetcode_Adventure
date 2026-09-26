class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n, 0);

        for (int i = n - 2; i >= 0; --i) {
            int curr = i + 1;
            
            // Jump forward using already computed results in res
            while (curr < n && temperatures[i] >= temperatures[curr]) {
                if (res[curr] == 0) {
                    curr = n; // No warmer day exists ahead
                    break;
                }
                curr += res[curr]; // Fast jump forward!
            }
            
            if (curr < n) {
                res[i] = curr - i;
            }
        }
        return res;
    }
};