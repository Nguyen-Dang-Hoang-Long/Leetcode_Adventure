using namespace std;
class Solution {
private:
    set<int> exist; 
public:
    bool hasDuplicate(vector<int>& nums) {
        exist.clear();
        for (int num : nums) {
            exist.insert(num);
        }
        return exist.size() != nums.size();
    }
};