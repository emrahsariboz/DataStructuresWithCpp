## Recurrence Relation of the problem

     L(j) = max {L(i) : (i,j) E } + 1 

          where 0<=i<j
 
 ## Algorithm
 
     for j in range(1, n):
        L(j) = max {L(i) : (i,j) E } + 1
     return max(L(j))
