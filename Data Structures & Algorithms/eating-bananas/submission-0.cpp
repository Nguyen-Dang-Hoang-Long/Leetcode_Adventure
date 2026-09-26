using namespace std;
class Solution {
public:

    int minEatingSpeed(vector<int>& piles, int h) {
        // find max pile in O(n), where n is size of input
        int max_k = -1;
        for (int p : piles) if (p > max_k) max_k = p;

        // bsearch k for O for O(logm)
        int l = 1, r = max_k;
        int last_res = -1;
        while (l <= r) {
            int k = l + (r-l)/2;
            long long total = 0;
            for (int p : piles) {
                total += (p + k - static_cast<long long>(1))/k;
            }
            //cout << "l: " << l << " r: " << r << " k: " << k << endl;
            //cout << "total: " << total << " vs h: " << h << endl; 
            if (total <= h) {
              //  cout << "valid, save, and find better k" << endl;
                last_res = k;
                r = k - 1;
            }
            else {
            //    cout << "k too small, find bigger k" << endl;
                l = k + 1;
            }
        }
        return last_res;
    }
};