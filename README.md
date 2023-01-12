### 1519. Number of Nodes in the Sub-Tree With the Same Label

<br/>

**Main idea to solve problem**: Find recursive relationship with subproblem

#### Algorithm: 
```
// label_nodes: map {label_name : [all ancestor node with label equal to label_name]}
// ans: stores number of nodes in sub-tree with same label

function countSubTrees(root):
  label_nodes[labels[root]].append(root); 
  for each node in label_node[labels[root]]: ++ans[node];
  for each neighbour of root: countSubTrees(neighbour);
  label_nodes[labels[root]].remove(root); 

  return ans;
```