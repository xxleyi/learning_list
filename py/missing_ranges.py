# -*- coding: utf-8 -*-

# Given a sorted integer array nums, where the range of elements are in the inclusive range [lower, upper], return its missing ranges.

# Example:
# Input: nums = [0, 1, 3, 50, 75], lower = 0 and upper = 99,
# Output: ["2", "4->49", "51->74", "76->99"]

from typing import List


def format_range(m: int, n: int) -> str:
    return f"{m + 1}" if m == n - 2 else f"{m + 1}->{n - 1}" if m < n - 2 else ""


def find_missing_ranges(nums: List[int], lo, hi) -> List[str]:
    if not nums:
        return [f"{lo}->{hi}"]
    res = []
    if head := format_range(lo - 1, nums[0]):
        res.append(head)
    for i in range(len(nums) - 2):
        if f := format_range(nums[i], nums[i + 1]):
            res.append(f)
    if tail := format_range(nums[-1], hi + 1):
        res.append(tail)

    return res


if __name__ == "__main__":
    nums = [3, 4, 5, 7, 10, 30]
    print(find_missing_ranges(nums, 0, 100))
    nums = [4]
    print(find_missing_ranges(nums, 0, 100))
    nums = []
    print(find_missing_ranges(nums, 0, 100))
