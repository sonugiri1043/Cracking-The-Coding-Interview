Find the mistake in the following code:

```c++
unsigned int i;
for (i = 100; i >= 0; --i )
    printf("%d\n", i);
```

An unsigned int is, by definition, always greater than or equal to zero. The for loop condition
will therefore always be true, and it will loop infinitely.
