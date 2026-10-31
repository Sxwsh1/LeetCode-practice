Brute forcing is O(n²).

I used the Two Pointer technique, but since the input isn't sorted, it requires sorting first, making it O(n log n). Using an `unordered_set` if we're only looking for the values, or an `unordered_map` if we need the indices, would instead give O(n) average time.

```cpp
unordered_map<int, int> seen;

for (int i = 0; i < nums.size(); i++) {
    int needed = target - nums[i];

    if (seen.contains(needed))
        return {seen[needed], i};

    seen[nums[i]] = i;
}

return {};
```