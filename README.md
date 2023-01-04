### 2244. Minimum Rounds to Complete All Tasks

<br/>

**Main idea to solve**:   
&emsp;n is natural number.   
&emsp;(n%3) can output 0, 1, 2  
&emsp;if n%3 == 0 then (n-2)%3 gives 1   
&emsp;if n%3 == 1 then (n-2)%3 gives 2   
&emsp;if n%3 == 2 then (n-2)%3 gives 0   


#### Algorithm: 
```
for each number in tasks     
  find minimum size array contains any number of 2 & 3 and whose sum is equal to that number.
  result += size of array;
```