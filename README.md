### 213. House Robber II

<br/>

**Main idea to solve problem**: Find recursive relationship with subproblem

#### Algorithm: 
```
def rob(nums):
  def dp(i, size):
    if(i>=size) return 0;
    return max(dp(i+1), dp(i+2) + nums[i]);
  return max(dp(0, nums.size-1), dp(1, nums.size));
```