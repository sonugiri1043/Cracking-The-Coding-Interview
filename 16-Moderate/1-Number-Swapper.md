## Number Swapper:
  Write a function to swap a number in place (that is, without temporary variables).

  
## Solution:
  Lets picture a and b on a number line for case where a > b

```bash

  |---------|----------------|
  0         b      diff      a
```

  First, we briefly set a to diff, which is the right side of the above number line.
  Then, when we add b and diff ( and store that value in b ), we get a.
  We now have b = a and a = diff. All that's left to do is to set a equal to b - diff.
  
```c++
  a = a - b; // a = diff
  b = b + a; // b now equals original a
  a = b - a; // a now equals original b
```




