#include <bits/stdc++.h>
using namespace std;

// global variables
int dp[1005][1005];
bool rotten[1005];
int v[1005];
int w[1005];

int main() {
    // speed up
    ios::sync_with_stdio(0); 
    cin.tie(0);
    
    int n, m, C;
    if (!(cin >> n >> m >> C)) return 0;
    
    // receive broken boards
    if (m > 0) {
        for (int i = 0; i < m; i++) {
            int id;
            cin >> id;
            rotten[id] = true;
        }
    }
    
    // receive value and weight
    for (int i = 1; i <= n; i++) cin >> v[i];
    for (int i = 1; i <= n; i++) cin >> w[i];
    
    // init dp array with -1 (unreachable)
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0; 
    
    // dp transitions
    for (int i = 0; i < n; i++) {
        // skip if current board is broken
        if (rotten[i]) continue;
        
        for (int j = 0; j <= C; j++) {
            // only push from valid states
            if (dp[i][j] != -1) {
                // try jumping 1, 2, or 3 steps
                for (int step = 1; step <= 3; step++) {
                    int nxt = i + step;
                    
                    // check bounds and broken boards
                    if (nxt <= n && !rotten[nxt]) {
                        int nxt_w = j + w[nxt];
                        
                        // check capacity limit
                        if (nxt_w <= C) {
                            // universe collision: keep max value for the same weight
                            dp[nxt][nxt_w] = max(dp[nxt][nxt_w], dp[i][j] + v[nxt]);
                        }
                    }
                }
            }
        }
    }
    
    // find max value at destination n across all weights
    int ans = -1;
    for (int j = 0; j <= C; j++) {
        if (dp[n][j] > ans) {
            ans = dp[n][j];
        }
    }
    
    // output
    if (ans == -1) cout << "IMPOSSIBLE\n";
    else cout << ans << "\n";
    
    return 0;
}