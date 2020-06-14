class Solution {
public:
    enum Color {WHITE, GRAY, BLACK};
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0 || grid.at(0).size() == 0){
            return 0;
        }
        int rows = grid.size();
        int cols = grid.at(0).size();

        //int moves[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}}

        //vector<vector<int>> moves(4, vector<int>(2)) = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

        vector<vector<int>> moves = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
        //vector<vector<int>> moves = {{0, 1}, {1, 0}};

        // 14:30
        // Allocate the matrix of colors with all white
        vector<vector<Color>> colors(rows, vector<Color>(cols, WHITE));

        int components = 0;
        // For each node, try to start a search
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid.at(i).at(j) == '1' && colors.at(i).at(j) == WHITE){
                    //printf("hello\n");
                    components++;
                    dfs(grid, colors, i, j, moves);

                }
            }
        }
        return components;
    }
    // 14:40
    //
    void dfs(vector<vector<char>>& grid, vector<vector<Color>> &colors, int i, int j, vector<vector<int>> &moves){

        //printf("%d %d %d\n", i, j, colors.at(i).at(j));
        // Paint node (i,j) gray
        colors.at(i).at(j) = GRAY;
        //vector<vector<int>> neighbors(8, vector<int>(2));
        int rows = grid.size();
        int cols = grid.at(0).size();
        int nI, nJ;
        int a, b;
        // Visit its neighbors
        for(auto move : moves){

            nI = i + move[0];
            nJ = j + move[1];
            //printf("neighbor: %d %d\n", nI, nJ);
            if(inBound(nI, nJ, rows, cols)){
                if(grid.at(nI).at(nJ) == '1' && colors.at(nI).at(nJ) == WHITE){
                    //printf("Hi\n");
                    dfs(grid, colors, nI, nJ, moves);
                }
            }
        }


        // Paint it black
        colors.at(i).at(j) = BLACK;
        // 14:58
    }


    inline bool inBound(int i, int j, int rows, int cols){
        return i >= 0 && j >= 0 && i < rows && j < cols;
    }
    // "finished code at": 14:58
    // Fixing bugs: 14:59 - 15:42
};

/*
Reading: 14:10 - 14:12

Solving: 14:13 - 14:19

Search how to use matrices in c++: 14:20 - 14:29
*/
