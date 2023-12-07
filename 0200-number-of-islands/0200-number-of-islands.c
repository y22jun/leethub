// DFS를 통해 연결된 육지를 찾고 방문한 셀은 '0'으로 표시한다.
void dfs(char** grid, int i, int j, int gridSize, int* gridColSize) {
    if (i < 0 || i >= gridSize || j < 0 || j >= *gridColSize || grid[i][j] == '0') {
        return;
    }

    // 현재 셀을 방문했다고 표시
    grid[i][j] = '0';

    // 인접한 셀들을 탐색
    dfs(grid, i - 1, j, gridSize, gridColSize); // 위
    dfs(grid, i + 1, j, gridSize, gridColSize); // 아래
    dfs(grid, i, j - 1, gridSize, gridColSize); // 왼쪽
    dfs(grid, i, j + 1, gridSize, gridColSize); // 오른쪽
}

// 그리드에서 섬의 개수를 찾는 함수
int numIslands(char** grid, int gridSize, int* gridColSize) {
    if (grid == NULL || gridSize == 0 || gridColSize == NULL || *gridColSize == 0) {
        return 0;
    }

    int islandCount = 0;

    // 그리드를 탐색
    for (int i = 0; i < gridSize; ++i) {
        for (int j = 0; j < *gridColSize; ++j) {
            if (grid[i][j] == '1') {
                // 방문하지 않은 육지를 발견하면 섬 개수를 증가시키고 DFS를 수행
                islandCount++;
                dfs(grid, i, j, gridSize, gridColSize);
            }
        }
    }

    return islandCount;
}