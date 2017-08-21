// O(nm * word_len) nm is the board size, time word_length. Using a dfs to do a brute force search.
// Faster than 72% - 86%

class Solution {
public:
    const int o1 [4] = {-1, 0, 1, 0};
    const int o2 [4] = {0, 1, 0, -1};
    int r, c;
    vector<vector<bool>> visited;
    
    bool brute_force_search (int x, int y, vector<vector<char>> & board, string & word, int pos){
        if (pos == word.length()) {
            return true;
        }
        visited[x][y] = true;
        for (int i=0; i<4; i++) {
            int x2 = x + o1[i];
            int y2 = y + o2[i];
            if (x2 >= 0 && x2 < r && y2 >= 0 && y2 < c) {
                if (word[pos] == board[x2][y2] && !visited[x2][y2]) {
                    if (brute_force_search(x2, y2, board, word, pos+1)) {
                        return true;
                    }
                }
            }
        }
        visited[x][y] = false;
        return false;
    }
    
    bool exist(vector<vector<char>> & board, string word) {
        if (word == "") { return true; }
        if (!board.size() || !board[0].size()) { return false; }
        r = board.size();
        c = board[0].size();
        visited = vector<vector<bool>> (r, vector<bool> (c, false));
        for (int i=0; i<r; i++) {
            for (int j=0; j<c; j++) {
                if (board[i][j] == word[0] && brute_force_search (i, j, board, word, 1)) {
                    return true;
                }
            }
        }
        return false;
    }
};
