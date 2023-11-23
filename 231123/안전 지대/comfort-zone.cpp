#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> town;
vector<int> dx = {0, 0, -1, 1};
vector<int> dy = {-1, 1, 0, 0};

vector<vector<int>> DFS(int x, int y, int rainLevel, vector<vector<int>> visited) {
    int nx, ny;
    visited[y][x] = 1;

    for (int i = 0; i < 4; i++) {
        nx = x + dx[i];
        ny = y + dy[i];
        if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[ny][nx] && town[ny][nx] > rainLevel)
            visited = DFS(nx, ny, rainLevel, visited);
    }
    return visited;
}

int GetZones(int rainLevel) {
    vector<vector<int>> visited(n, vector<int>(m, 0));
    int zones = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && town[i][j] > rainLevel) {
                zones++;
                visited = DFS(j, i, rainLevel, visited);
            }
        }
    }
    return zones;
}

int main() {
    int maxHeight = 0;
    int maxZone = 0;
    int answer = 0;
    int zones;

    cin >> n >> m;
    town = vector<vector<int>>(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> town[i][j];
            if (maxHeight < town[i][j])
                maxHeight = town[i][j];
        }
    }
    for (int i = 1; i <= maxHeight; i++) {
        zones = GetZones(i);
        if (maxZone < zones) {
            maxZone = zones;
            answer = i;
        }
    }
    cout << answer << " " << maxZone;
    return 0;
}