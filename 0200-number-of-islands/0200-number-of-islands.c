void dfs(char** grid, int i, int j, int gridSize, int* gridColSize) {
    if (i < 0 || i >= gridSize || j < 0 || j >= *gridColSize || grid[i][j] == '0') {
        return;
    }

    // Mark the current cell as visited
    grid[i][j] = '0';

    // Explore adjacent cells
    dfs(grid, i - 1, j, gridSize, gridColSize); // Up
    dfs(grid, i + 1, j, gridSize, gridColSize); // Down
    dfs(grid, i, j - 1, gridSize, gridColSize); // Left
    dfs(grid, i, j + 1, gridSize, gridColSize); // Right
}

int numIslands(char** grid, int gridSize, int* gridColSize) {
    if (grid == NULL || gridSize == 0 || gridColSize == NULL || *gridColSize == 0) {
        return 0;
    }

    int islandCount = 0;

    // Traverse the grid
    for (int i = 0; i < gridSize; ++i) {
        for (int j = 0; j < *gridColSize; ++j) {
            if (grid[i][j] == '1') {
                // Found unvisited land, increment island count and perform DFS
                islandCount++;
                dfs(grid, i, j, gridSize, gridColSize);
            }
        }
    }

    return islandCount;
}