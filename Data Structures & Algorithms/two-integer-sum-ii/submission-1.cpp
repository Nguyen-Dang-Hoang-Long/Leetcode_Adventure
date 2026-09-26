using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int index1_cnt= 1;
        int index2_cnt = numbers.size();
        auto index1 = numbers.begin();
        auto index2 = numbers.end() - 1;
        while (index1 != index2) {
            if (*index1 + *index2 == target) return {index1_cnt, index2_cnt}; 
            if (*index1 + *index2 > target) {
                index2--;
                index2_cnt--;
            }
            if (*index1 + *index2 < target) {
                index1++;
                index1_cnt++;
            }
        }
        return {};
    }
};
