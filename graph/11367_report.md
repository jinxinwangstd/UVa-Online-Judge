## Problem description

Given a connected weighted graph length that stores the road length between E pairs of cities i and j ($1 \le V \le 1000, 0 \le E \le 10000$), the price p[i] of fuel at each city i, and the fuel tank capacity c of a car ($1 \le c \le 100$), determine the cheapest trip cost from starting city s to ending city e using a car with fuel capacity c. All car use one unit of fuel per unit of distance and start with an empty fuel tank.

## Algorithm analysis

Through analysis, we can find that to determine the minimal distance between two cities, we need not only the starting city, but also the fuel it have. So the state of this problem contains two piece of information: (location, fuel). Then we can construct a state graph, in which a vertex represent a state. In this state graph, the start vertex is (s, 0) and the ending vertex is (t, eny). There are two types of edges in the graph: 0-weighted edge that goes from vertex (x, fuel) to vertex (y, fuel - length(x, y)) if the car has sufficient fuel to travel from vertex x to vertex y, and the p[x]-weighted edge that goes from vertex (x, fuel) to vertex (x, fuel+1) if the car can refuel at vertex x by one unit of fuel.
Then we just run Dijkstra's algorithm on the state graph and compare the distance between (s, 0) to (t, any) and select the least one.

## Knowledge base

1. Graph modeling:
   Sometimes, the graph in the problem is not the graph we can use. Instead, we need to construct a new graph based on the graph the problem provided.
   Like in this problem, we need to construct the state graph based on the city location and fuel units.

2. Dijkstra's algorithm to solve the SSSP on weighted graph:

   ```c++
   typedef vector<int> vi;
   typedef pair<int, int> ii;
   typedef vector<ii> vii;
   
   vi dist(V, INT_MAX);
   dist[s] = 0;
   priority_queue< ii, vector<ii>, greater<ii> > pq;
   pq.push(ii(0, s));
   while (!pq.empty()) {
       ii front = pq.top();
       pq.pop();
       int d = front.first, u = front.second;
       if (d > dist[u])
           continue;
       int num = (int) g[u].size();
       for (int i = 0; i != num; ++i) {
           ii v = g[u][i];
           if (dist[u] + v.second < dist[v.first]) {
               dist[v.first] = dist[u] + v.second;
               pq.push(ii(dist[v.first], v.first));
           }
       }
   }
   // finish Dijkstra's algorithm
   ```

   