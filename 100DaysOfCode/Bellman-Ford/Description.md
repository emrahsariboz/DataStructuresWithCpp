### Bellman-Ford

Its a single source shortest path algorithm. Djisktra may or may not give an expected
result when we have a negative edges. This is why Bellman-ford invented.

The only deficiency of the bellman-ford (beside runtime) is negative cycle.

### Runtime

We need to relaxate each edge |n-1| time where 'n' is the total number of vertices.

Worst case runtime of the algorithm is O(n^3) because of the relaxation where

E = n* (n-1) / 2 edges, V = |n-1| which results O(n^3).


