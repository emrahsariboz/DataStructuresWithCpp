## Recurrence Relation

At simplest case we have two choice. Pick the item or not.

You need to choose the maximum value between pick or leave.

### Max(A,B)

A is ValueOf(i) + K(i-1, totalWeight - WeightOf(i). 

Value of the item + K(Previous value, remaining weight in the back after we pick the item).

B is the case for not picking the item.

K(i,w) = max( ValueOf(i) + K(i-1, totalWeight - WeightOf(i)), K(i-1, w))

where K is 2D array, i stands for items and w stands for weights. 
