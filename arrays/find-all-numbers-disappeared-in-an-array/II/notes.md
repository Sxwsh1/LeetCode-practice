My 1st approach was to create an `unordered_set` containing every value in `[lower, upper]`, then erase every value found in `nums`.  
The remaining values are the missing numbers. I then put them in a vector and sorted it. Using this vector to build the missing ranges is pretty straightforward.

**Complexity:** `O(n + R log R)` for time, where `R = upper - lower + 1`, and `O(R)` for space.

I then figured the sorting and the back-and-forth between the set and vector were inefficient.  
Instead, I could iterate directly from `lower` to `upper` and build the missing-numbers vector along the way, which naturally keeps the values in order. Checking whether each number exists in `nums` would normally require a nested loop, giving `O(R * n)`. This is avoided by still using an `unordered_set`, but this time containing the elements of `nums`, allowing average `O(1)` lookups.

**Complexity:** `O(n + R)` for time and `O(n + R)` for space.
