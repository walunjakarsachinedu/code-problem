### 1443. Minimum Time to Collect All Apples in a Tree

<br/>

**Main idea to solve problem**: Find recursive relationship with subproblem

#### Algorithm: 
```
function minTime(root)
  time = 0;
  for each neighbour of root
    if(neighbour is apple || neighbours subTree contains apple) time += 2 + minTime(nei);
  return time;
```