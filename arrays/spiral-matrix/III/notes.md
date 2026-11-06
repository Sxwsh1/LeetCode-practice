A spiral follows increasing movement lengths: 1 right, 1 down, 2 left, 2 up, 3 right, 3 down, etc. The movement length increases after every two direction changes. For this problem, we keep moving outside the grid but only record valid positions.

Two potential code improvements:

- Use `reserve()` to avoid unnecessary reallocations since the final size of `matrix` is known in advance.
- Add an early `return` inside the nested loops once all positions have been recorded.