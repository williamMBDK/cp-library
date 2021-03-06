pair<vector<int>, vector<vector<int>>> get_components(vector<vector<int>>& adj){
	int n = (int)adj.size();
	vector<int> component_map (n, -1);
	vector<vector<int>> component_groups;
	for(int i = 0; i < n; i++){
		if(component_map[i] == -1){
			queue<int> q;
			q.push(i);
			component_groups.push_back({});
			int idx = (int)component_groups.size() - 1;
			while(!q.empty()){
				int curr = q.front(); q.pop();
				if(component_map[curr] != -1) continue;
				component_groups[idx].push_back(curr);
				component_map[curr] = idx;
				for(auto& e : adj[curr]){
					if(component_map[e] == -1) q.push(e);
				}
			}
		}
	}
	// component_map[node] is the component of the node
	// node is in component_groups[component_map[node]]
	return {component_map, component_groups};
}
