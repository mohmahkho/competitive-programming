    // dist[v][v] = 0;
    // dist[u][v] = 1 if there is edge between them
    // other dists = INF at the beginning
    
    for(int k = 1; k <= n; ++k) {
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= n; ++j) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
