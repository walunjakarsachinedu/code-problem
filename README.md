### 198. House Robber

<br/>

**Main idea to solve problem**: Find recursive relationship with subproblem

<br/><br/>

#### Algorithm: 
```
def dp(i);
  if(i>=nums.size) return 0;
  return max(dp(i+1), dp(i+2) + nums[i]);
```