class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        k %=  (m*n);

        vector<vector<int>> temp(m,vector<int>(n));

        for(int r=0; r<m;r++){
          for(int c=0;c<n;c++){
            int idx = r*n+c;
            int newIdx = (idx + k)%(m*n);

            int newRow = newIdx/n;
            int newCol = newIdx % n;

            temp[newRow][newCol] = grid[r][c];

          }
        }
        return temp;


    }
};