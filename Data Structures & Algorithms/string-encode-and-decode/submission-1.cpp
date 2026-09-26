

using namespace std;
class Solution {
public:

    string encode(vector<string>& strs) {
        string res;
        for (string str: strs) {
            res.append(to_string(str.size()));
            res.push_back('#');
            res.append(str);
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        for (int i = 0; i < s.size();) {
            // Calc the string lenght
            string len;
            // First we hit a num, until we hit a '#', its a number
            while (s[i] != '#') {
                len.push_back(s[i]);
                i++;
            } 
            // Once it did hit, transfer the string collected to a num
            int num = stoi(len);
            i++; // push past the '#'
            // Collect the string
            res.push_back(s.substr(i, num));
            i += num;
        }
        return res;
    }
};