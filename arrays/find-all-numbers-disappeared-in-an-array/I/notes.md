Another possible solution is to iterate over `nums` and, for each encountered `x`, make `nums[x - 1]` negative. Then iterate again to create the `disappeared` list, appending the indices + 1 of positive values in `nums`.

Advantage: O(1) extra space outside of the returned list.