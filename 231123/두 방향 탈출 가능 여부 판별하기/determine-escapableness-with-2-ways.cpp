#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> grid;
vector<vector<int>> visited;
vector<int> dx = {0, 1};
vector<int> dy = {1, 0};

void DFS(int x, int y) {
    if (visited[y][x]) return;
    visited[y][x] = 1;

    for (int i = 0; i < 2; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[ny][nx] && grid[ny][nx])
            DFS(nx, ny);
    }
}

int main() {
    cin >> n >> m;
    grid = vector<vector<int>>(m, vector<int>(n, 0));
    visited = vector<vector<int>>(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];
    }
    DFS(0, 0);
    cout << visited[m-1][n-1];
}