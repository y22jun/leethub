#include <stdio.h>
#include <stdlib.h>

int min(int a, int b) {
    return a < b ? a : b;
}

int minPathSum(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize;
    int n = *gridColSize;

    // 동적 계획법을 위한 2D 배열 동적 할당
    int** dp = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        dp[i] = (int*)malloc(n * sizeof(int));
    }

    // 시작 지점의 최소 경로 합은 그리드의 첫 번째 원소와 같음
    dp[0][0] = grid[0][0];

    // 첫 번째 행의 각 셀에 대한 최소 경로 합 계산
    for (int i = 1; i < n; i++)
        dp[0][i] = grid[0][i] + dp[0][i - 1];

    // 첫 번째 열의 각 셀에 대한 최소 경로 합 계산
    for (int j = 1; j < m; j++)
        dp[j][0] = grid[j][0] + dp[j - 1][0];

    // 나머지 셀에 대한 최소 경로 합 계산
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = grid[i][j] + min(dp[i][j - 1], dp[i - 1][j]);
        }
    }

    // 최종 결과는 마지막 셀의 최소 경로 합
    int result = dp[m - 1][n - 1];

    // 동적으로 할당한 메모리를 해제
    for (int i = 0; i < m; i++) {
        free(dp[i]);
    }
    free(dp);

    return result;
}