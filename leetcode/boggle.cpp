
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        for(int i = 0 ; i < board.size() ; ++i)
        {
            for(int j = 0 ; j < board[i].size() ; ++j)
            {
                if(dfs(board, i, j, word, 0))  return true;
            }
        }
        return false;
    }
    
private:
    bool dfs(vector<vector<char>>& board, int i, int j, string word, int count)
    {
        if(count == word.size())
            return true;
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size())
            return false;
        if(count >= word.size())
            return false;
        if(word[count] != board[i][j])
            return false;
        
        board[i][j] = '*';
        bool res = dfs(board, i, j + 1, word, count + 1) || dfs(board, i, j - 1, word, count + 1)
            || dfs(board, i + 1, j, word, count + 1) || dfs(board, i - 1, j, word, count + 1);
        
        board[i][j] = word[count];
        return res;
    }
};
