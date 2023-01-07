### 134. Gas Station

<br/>

**Main idea to solve**:
#### finding the subArray in circular array with max sum
```
use first for loop for finding max sum in array using kadane's algorithm.
then use second for loop for iterating remaining part of array (rotated part) & again apply kadane's algorithm.
```

<br/><br/>

#### Algorithm: 
```
newArray = gas - cost;
find range of subArray with maxSum in newArray;
return starting index of that range;
```