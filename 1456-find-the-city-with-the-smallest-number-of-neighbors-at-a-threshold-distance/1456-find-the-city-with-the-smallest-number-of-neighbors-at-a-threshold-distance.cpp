typedef pair<int, int>p; 
class Solution {
public:
        //IN DIJKSTRA, we need to apply it on each vertex 
        // in a pq, store the distance and vertex
        // if adis+dis < res[anode] -> update the distance 
        // but have to apply on each vertex now
        // every row index is a source 
        // will have a result vector for each column 
//     int findRequiredCity(vector<vector<int>> matrix, int n, int threshold)
//     {
//         int minCount = INT_MAX; 
//         int city = -1; 
//         for(int i=0; i<n; i++)
//         {
//             int countReach = 0; 
//             for(int j=0; j<n; j++)
//             {
//                 if(i!=j && matrix[i][j]<=threshold)
//                     countReach++; 
//             }

//             if(countReach <= minCount)
//             {
//                 minCount = countReach; 
//                 city = i; 
//             }
//         }

//         return city; 
//     }

//     vector<int> dijkstra(unordered_map<int, vector<p>>adj, int source, vector<int>&result, int n)
//     {
//         priority_queue<p, vector<p>, greater<p>> pq; 
//         pq.push({0, source});
//         fill(result.begin(), result.end(), 1e5);
//         result[source] = 0; 

//         while(!pq.empty())
//         {
//             int node = pq.top().second; 
//             int d = pq.top().first; 
//             pq.pop();

//             for(auto &it : adj[node])
//             {
//                 int anode = it.first;
//                 int ad = it.second;

//                 if(d + ad < result[anode])
//                 {
//                     result[anode] = d + ad; 
//                     pq.push({d + ad, anode}); 
//                 }
//             }
//         }

//         return result; 



//     }

// //DIJKSTRA 
//     int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) 
//     {
//         vector<vector<int>> matrix(n, vector<int>(n, 1e5)); 
//         for(int i=0; i<n; i++) matrix[i][i] = 0; 

//         unordered_map<int, vector<p>>adj;
//         for(auto &it : edges)
//         {
//             int u = it[0];
//             int v = it[1];
//             int wt = it[2];

//             adj[u].push_back({v, wt});
//             adj[v].push_back({u, wt}); 
//         }

//         vector<int> result(n, 1e5); 

//         for(int i=0; i<n; i++)
//         {
//             dijkstra(adj, i, matrix[i], n);
//         }

//         return findRequiredCity(matrix, n, distanceThreshold);
//     }


// FLOYD WARSHAL 
    // int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) 
    // {
    //     vector<vector<int>> grid(n, vector<int>(n, 1e5));
    //     for(int i=0; i<n; i++) grid[i][i] = 0; 

    //     for(auto &it : edges)
    //     {
    //         int i = it[0];
    //         int j = it[1];
    //         int d = it[2];

    //         grid[i][j] = d; 
    //         grid[j][i] = d; 
    //     }

    //     //now we have stored the distance of each vertex from each vertex in a grid.
    //     // now we apply floyd warshal to minimise each distance 

    //     for(int via = 0; via < n; via++)
    //     {
    //         for(int i=0; i<n; i++)
    //         {
    //             for(int j=0; j<n; j++)
    //             {
    //                 grid[i][j] = min(grid[i][j], grid[via][j]+grid[i][via]);
    //             }
    //         }
    //     }

    //     //got all the min distances. Now we need to store the nnumber of places it can go to staying in the threshold   limit

    //     vector<int> cities(n, 0);

    //     for(int i=0; i<n; i++)
    //     {
    //         for(int j=0; j<n; j++)
    //         {
    //             if(grid[i][j] <= distanceThreshold) cities[i]++;
    //         }
    //     } 

    //     priority_queue<int> greatestCity_pq; 

    //     //now find the minimum number of cities can be travelled tp
    //     int minCities = n;
    //     for(int i=0; i<n; i++)
    //     {
    //         if(cities[i] < minCities) minCities = cities[i];
    //     }
        
    //     for(int i=0; i<n; i++)
    //     {
    //         if(cities[i] == minCities)
    //             greatestCity_pq.push(i);
    //     }

    //     return greatestCity_pq.top();
    // }

    // BELLMAN FORD ALGORITHM 
    // relax eaxh vertex v-1 times for each source 

//     vector<int> bellmanFord(vector<vector<int>> edges, int source, vector<int>&result, int n)
//     {
//         fill(result.begin(), result.end(), 1e7);

//         result[source] = 0;

//         for(int cnt = 1; cnt <= n-1; cnt++)
//         {
//             for(auto &edge : edges)
//             {
//                 int node = edge[0];
//                 int anode = edge[1];
//                 int d = edge[2];

//                 if(result[node] != 1e7 && result[node]+d < result[anode])
//                 {
//                     result[anode] = result[node] + d; 
//                 }

//                 if(result[anode] != 1e7 && result[anode]+d < result[node])
//                 {
//                     result[node] = result[anode] + d; 
//                 }
//             }
//         }

//         return result; 
//     }

//     int findRequiredCity(vector<vector<int>> matrix, int n, int threshold)
//     {
//         int minCount = INT_MAX; 
//         int city = -1; 
//         for(int i=0; i<n; i++)
//         {
//             int countReach = 0; 
//             for(int j=0; j<n; j++)
//             {
//                 if(i!=j && matrix[i][j]<=threshold)
//                     countReach++; 
//             }

//             if(countReach <= minCount)
//             {
//                 minCount = countReach; 
//                 city = i; 
//             }
//         }

//         return city; 

//     }

//     int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) 
//     {
//         vector<vector<int>> matrix(n, vector<int>(n, 1e9+7)); 
//         for(int i=0; i<n; i++) matrix[i][i] = 0; 

//         for(auto &it : edges)
//         {
//             int u = it[0];
//             int v = it[1];
//             int d = it[2];

//             matrix[u][v] = d; 
//             matrix[v][u] = d; 
//         }


//         for(int i=0; i<n; i++)
//         {
//             bellmanFord(edges, i, matrix[i], n);
//         }

//         return findRequiredCity(matrix, n, distanceThreshold);
//     }

  int dijkstra(int source, int n, int distanceThreshold, vector<vector<pair<int, int>>>&adj)
  {
      vector<int>dis(n, INT_MAX); 
      dis[source] = 0; 
      priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq; 

      pq.push({0, source});
    
      while(!pq.empty())
      {
        int u = pq.top().second; 
        int wt = pq.top().first; 
        pq.pop(); 

        for(auto &vec : adj[u])
        {
            int v = vec.first; 
            int awt = vec.second; 

            if(awt + wt < dis[v])
            {
                dis[v] = awt + wt; 
                pq.push({awt+wt, v});
            }
        }
      }

      //for a given source we calculate how many are below/equal to threhold distance 
      int count = 0; 

      for(int i=0; i<n; i++)
      {
         if(dis[i] <= distanceThreshold) count++; 
      }

      return count; 
  }

 int bellmanFord(int source, int n, int threshold, vector<vector<pair<int, int>>>adj, vector<vector<int>>edges)
 {
    vector<int>result(n, INT_MAX); 
    result[source] = 0; 

    for(int i=1; i<n; i++)
    {
        for(auto &edge : edges)
        {
            int u = edge[0]; 
            int v = edge[1]; 
            int wt = edge[2];

            if(result[u] != INT_MAX && result[u]+wt<result[v])
            {
                result[v] = result[u] + wt; 
            }

            if(result[v] != INT_MAX && result[v] + wt < result[u])
            {
                result[u] = result[v] + wt;
            }
        }
    }
    int count = 0; 

    for(int i=0; i<n; i++)
    {
        if(result[i] <= threshold) count++; 
    }

    return count; 
 }

   //dijkstra is to be applied on every single one node 
//  int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) 
//  {
//     // dijkstra has to be applied on every node to be able to find out the min distance that every node takes from the other nodes 

//     // will have to be stored in a 2d array for it 
//     // we have to find out min cities within threshold distance 
//     // min cities means the least num of cities within the threshold dist

//     // vector<pair<int,int>>adj(n); 

//     vector<vector<pair<int, int>>>adj(n);
// for(const auto& edge : edges)
// {
//     int u = edge[0]; 
//     int v = edge[1];
//     int wt = edge[2]; 

//     adj[u].push_back({v, wt}); 
//     adj[v].push_back({u, wt}); 
// }
//     int count = INT_MAX; 
//     int city = 0; 

//     // vector<vector<int>>dist(n, vector<int>(n, INT_MAX)); 
//     for(int i=0; i<n; i++)
//     {
//         int mincities = bellmanFord(i, n, distanceThreshold, adj, edges);
//         if(mincities <= count) 
//         {
//             count = mincities; 
//             city = i; 
//         }
//         // count = min(count, mincities);
//     }
//     return city; 
//  }
   // now trying out bellman ford algo 
  // in bellman ford, we relax the edges (v-1) times and we get the 
  // min distane to all edges 






// NOW TRYING OUT FLYOD WARSHAL ALGORITHM 
  int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) 
 {
    // dijkstra has to be applied on every node to be able to find out the min distance that every node takes from the other nodes 

    // will have to be stored in a 2d array for it 
    // we have to find out min cities within threshold distance 
    // min cities means the least num of cities within the threshold dist

    vector<vector<int>>dis(n, vector<int>(n, 1e5));
    for(auto &edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];

        dis[u][v] = wt;
        dis[v][u] = wt;
    }

// Initialize distances
        for (int i = 0; i < n; i++) {
            dis[i][i] = 0;
        }

    //applying floyd warshal 
    for(int via=0; via<n; via++)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(dis[i][via]!=1e5 && dis[via][j]!=1e5)
                    dis[i][j] = min(dis[i][j], dis[i][via]+dis[via][j]);
            }
        }
    }

    int city = 0; 
    int mincount = INT_MAX; 
    for(int i=0; i<n; i++)
    {
        int count = 0; 
        for(int j=0; j<n; j++)
        {
            if(dis[i][j] <= distanceThreshold) count++;
        }

        if(count <= mincount)
        {
            mincount = count; 
            city = i; 
        }
    }

    return city;
 }

};