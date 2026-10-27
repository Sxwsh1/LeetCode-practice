- Look for ways to reorganize the input (e.g. sorting) to make the problem easier.
- Look for what's making the solution slow and whether a better data structure can fix it.

Here, searching the `seen` vector for every number was O(n), so O(n²) overall.
`unordered_set` stores unique values and has O(1) average lookup. Basic operations: `insert()`, `contains()`, `erase()`, `size()`, `clear()`.
