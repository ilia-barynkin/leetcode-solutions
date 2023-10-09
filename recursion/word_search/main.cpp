#include <vector>
#include <string>
#include <set>
#include <cassert>

using namespace std;
typedef pair<char, char> LetterCell;

class Solution {
public:
    bool backtrack(vector<vector<char>>& board, char r, char c, string word) {
        if (r < 0 || board.size() == r || c < 0 || board[r].size() == c)
            return false;
        
        if (board[r][c] != word.back())
            return false;

        word.pop_back();
        char original = board[r][c];

        board[r][c] = '#';

        if (word.empty())
            return true;

        bool res =
            backtrack(board, r + 1, c, word) ||
            backtrack(board, r - 1, c, word) ||
            backtrack(board, r, c + 1, word) ||
            backtrack(board, r, c - 1, word);

        board[r][c] = original;

        return res;
    }

    bool exist(vector<vector<char>>& board, string word) {
        //std::reverse(word.begin(), word.end());
        bool res = false;
        
        for (auto i = 0; i < board.size(); ++i) {
            for (auto j = 0; j < board[0].size(); ++j) {
                if (backtrack(board, i, j, word)) {
                    res = true;
                    break;
                }
            }
        }

        return res;
    }

    bool exist(const vector<vector<char>>& board, string word) {
        return exist(const_cast<vector<vector<char>>&>(board), word);
    }
};

int main(int argc, char* argv[]) {
    Solution sol;

    assert(sol.exist({{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}}, "ABCCED"));
    assert(sol.exist({{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}}, "SEE"));
    assert(!sol.exist({{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}}, "ABCB"));
    assert(sol.exist({{'B','D','T','A'},{'A','T','C','S'},{'A','D','E','E'},{'A','D','E','E'}}, "TDBATC"));
    assert(!sol.exist({{'A','A','A','A','A','A'},{'A','A','A','A','A','A'},{'A','A','A','A','A','A'},{'A','A','A','A','A','A'},{'A','A','A','A','A','A'},{'A','A','A','A','A','A'}}, 
        "BAAAAAAAAAAAAAA"));

    assert(sol.exist({{'A','B','C','E'},{'S','F','E','S'},{'A','D','E','E'}}, "ABCESEEEFS"));

    //'A','B','C','E'
    //'S','F','E','S'
    //'A','D','E','E'

    return 0;

}