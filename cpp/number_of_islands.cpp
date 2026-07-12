#include <iostream>
#include <vector>

using namespace std;


// https://leetcode.com/problems/number-of-islands
class Solution{
    public:
        // Sink islands when they pop up.
        void dfs(vector<vector<char>>& grid, int r, int c){
            // Define the grid size.
            int m = grid.size(); // rows
            int n = grid[0].size(); // cols

            // If out of bounds or in water or visited, stop.
            if (r < 0 || c < 0 || r >= m || c >= n || grid[r][c] == '0') return;

            // Otherwise, mark as visited / water
            grid[r][c] = '0';

            // Then do a search in all the surrounding spaces/
            dfs(grid, r+1, c);
            dfs(grid, r-1, c);
            dfs(grid, r, c+1);
            dfs(grid, r, c-1);
        }


        int NumIslands(vector<vector<char>>& grid){
            int m = grid.size(); // rows
            int n = grid[0].size(); // cols

            // Counting number of islands.
            int count {0};

            // Loop through the grid spaces.
            for (int r = 0; r < m; r++) {
                for (int c = 0; c<n; c++){
                    // If island present, index counter by one and fill it.
                    if (grid[r][c] == '1'){
                        cout << " Found island! Sinking it." << endl;
                        count++;
                        dfs(grid, r, c);
                    }
                }
            }
            cout << count << " islands found." << endl;
            return count;
        }
};

int main(){
    Solution sol;

    vector<vector<char>> grid1 = {
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'}
    };
    sol.NumIslands(grid1);


    return 0;
}