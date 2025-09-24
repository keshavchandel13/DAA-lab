#include <bits/stdc++.h>
using namespace std;

vector<string> paths;
int n;

// Directions: D, L, R, U
int dx[] = {1, 0, 0, -1};
int dy[] = {0, -1, 1, 0};
char dir[] = {'D', 'L', 'R', 'U'};

bool is_safe(int x, int y, vector<vector<int>>& maze, vector<vector<int>>& visited) {
    return (x >= 0 && x < n && y >= 0 && y < n && maze[x][y] == 1 && !visited[x][y]);
}

void backtrack(int x, int y, vector<vector<int>>& maze, vector<vector<int>>& visited, string path) {
    if (x == n - 1 && y == n - 1) { // reached destination
        paths.push_back(path);
        return;
    }

    visited[x][y] = 1;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (is_safe(nx, ny, maze, visited)) {
            backtrack(nx, ny, maze, visited, path + dir[i]);
        }
    }

    visited[x][y] = 0; // backtrack
}

vector<string> findPaths(vector<vector<int>>& maze) {
    n = maze.size();
    vector<vector<int>> visited(n, vector<int>(n, 0));
    if (maze[0][0] == 0) return {};
    backtrack(0, 0, maze, visited, "");
    sort(paths.begin(), paths.end());
    return paths;
}

int main() {
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };

    auto result = findPaths(maze);
    if (result.empty()) {
        cout << "No path found\n";
    } else {
        for (auto &p : result) cout << p << "\n";
    }
}
