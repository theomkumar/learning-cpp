i	//KAHN's ALGO (TOPOLOGICAL SORT USING BFS)
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> inDegree(V,0);
	    for (int i = 0; i < V; i++){
	        for (auto &v : adj[i]){
	            inDegree[v]++;
	        }
	    }
	    queue<int>q;
	    for (int i = 0; i < V; i++){
	        if (inDegree[i] == 0){
	            q.push(i);
	        }
	    }

	    while (!q.empty()) {
	        int u = q.front();
	        res.push_back(u);
	        q.pop();
	        
	        for (auto &v : adj[u]){
	            if (--inDegree[v] == 0)
	                q.push(v);
	        }
	    }
	   
	    return res;
	}