Let `k` denote the maximum possible value in `nums`.

A better approach with O(n + k) time and O(k) auxiliary space is to count the occurrences of each value in `[0, k]` using a `count` vector, then compute cumulative frequencies:

```cpp
for (int i = 1; i <= k; i++)
    count[i] += count[i - 1];
```

This makes `count[i]` contain the number of elements less than or equal to `i`.