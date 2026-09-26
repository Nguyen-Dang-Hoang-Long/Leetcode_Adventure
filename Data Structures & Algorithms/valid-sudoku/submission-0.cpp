#define LENGTH 9
using namespace std;
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // check each row/col
        for (int i = 0; i < LENGTH; i++) {
            // per row/col, one hashset is used to determine existence of duplicate
            set<char> dup_row, dup_col, dup_box;
            for (int j = 0; j < LENGTH; j++) {
                // ignore empty cell
                // fail to insert into set => exist
                if (board[i][j] != '.' && !dup_row.insert(board[i][j]).second) 
                    return false;
                // swap index
                if (board[j][i] != '.' && !dup_col.insert(board[j][i]).second) 
                    return false;
                // check box
                int boxRow = 3 * (i / 3) + (j / 3);
                int boxCol = 3 * (i % 3) + (j % 3);
                if (board[boxRow][boxCol] != '.' && !dup_box.insert(board[boxRow][boxCol]).second) 
                    return false;
            }
        }
        return true;
    }
};