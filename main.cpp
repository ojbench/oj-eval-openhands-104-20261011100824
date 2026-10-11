#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct Point {
    int x, y, dist;
    Point(int x, int y, int dist) : x(x), y(y), dist(dist) {}
};

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> grid(m, vector<int>(n));
    int start_x = -1, start_y = -1, home_x = -1, home_y = -1;
    vector<pair<int, int>> umbrella_stores;
    
    // Read input and find positions
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 2) {
                start_x = i;
                start_y = j;
            } else if (grid[i][j] == 3) {
                home_x = i;
                home_y = j;
            } else if (grid[i][j] == 4) {
                umbrella_stores.push_back({i, j});
            }
        }
    }
    
    // Directions for moving up, down, left, right
    vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    // BFS to find shortest path from start to any umbrella store, then to home
    auto bfs = [&](int start_x, int start_y, int target_x, int target_y, bool find_umbrella = false) -> int {
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        queue<Point> q;
        
        dist[start_x][start_y] = 0;
        q.push(Point(start_x, start_y, 0));
        
        while (!q.empty()) {
            Point curr = q.front();
            q.pop();
            
            if (curr.x == target_x && curr.y == target_y) {
                return curr.dist;
            }
            
            for (auto& dir : dirs) {
                int nx = curr.x + dir.first;
                int ny = curr.y + dir.second;
                
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && 
                    grid[nx][ny] != 1 && dist[nx][ny] == INT_MAX) {
                    
                    // If we're looking for an umbrella store, we need to check if this is one
                    if (find_umbrella && grid[nx][ny] == 4) {
                        return curr.dist + 1;
                    }
                    
                    dist[nx][ny] = curr.dist + 1;
                    q.push(Point(nx, ny, curr.dist + 1));
                }
            }
        }
        
        return -1; // No path found
    };
    
    // Find shortest path from start to any umbrella store
    int to_umbrella = INT_MAX;
    for (auto& store : umbrella_stores) {
        int dist = bfs(start_x, start_y, store.first, store.second, true);
        if (dist != -1) {
            to_umbrella = min(to_umbrella, dist);
        }
    }
    
    if (to_umbrella == INT_MAX) {
        cout << -1 << endl;
        return 0;
    }
    
    // Find shortest path from umbrella store to home
    int to_home = bfs(umbrella_stores[0].first, umbrella_stores[0].second, home_x, home_y);
    
    // We need to try all umbrella stores to find the shortest path
    for (auto& store : umbrella_stores) {
        int dist = bfs(store.first, store.second, home_x, home_y);
        if (dist != -1) {
            to_home = min(to_home, dist);
        }
    }
    
    if (to_home == INT_MAX) {
        cout << -1 << endl;
        return 0;
    }
    
    cout << to_umbrella + to_home << endl;
    
    return 0;
}