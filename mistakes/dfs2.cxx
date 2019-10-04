/*
If you have two dfs functions and named them dfs and dfs2, make sure you are calling dfs2 inside dfs2!
*/

// Issue
void dfs(string& s) {
  vis[s] = true;
  for(auto& t : g[s]) {
    if(vis[t] == false) dfs(t);
  }
}
 
void dfs2(string& s) {
  vis[s] = true;
  for(auto& t : gp[s]) {
    if(vis[t] == false) dfs(t);
  }
}

// Solution : Just call dfs inside dfs and dfs2 inside dfs2!
