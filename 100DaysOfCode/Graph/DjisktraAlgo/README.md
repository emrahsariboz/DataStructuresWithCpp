# Run time explanation of Djisktra Algorithm

Assuming we used min-heap for the priority queue implementation.

Heapify takes O (V) time where V is the number of vertext we have. 

Delete-min operation takes place O(log n) times and we do this for every vertex. O(V log V).

Inside for loop, we have decrease key operation takes place in O(log n) and we do this for every edge. O( E log V)

##### Adding above results gives us O (E + V log V) using binary heap. To speed up the process, we could use fibonocci heap as a priority queue 
##### where decrease key operation would take O(1) time. Thus, we will have O(E + VlogV). 
