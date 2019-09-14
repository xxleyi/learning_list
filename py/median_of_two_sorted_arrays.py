# -*- coding: utf-8 -*-
from typing import *

class Solution:
    def findMedianSortedArrays(self, a: List[int], b: List[int]) -> float:
        class SafeList(list):
            def __getitem__(self, idx):
                if idx < 0:
                    return float("-inf")
                try:
                    return super().__getitem__(idx)
                except:
                    return float("inf")

        a, b = sorted((a, b), key=len)
        a, b = SafeList(a), SafeList(b)
        m, n = len(a), len(b)
        after = (m + n + 1) // 2

        lo, hi = 0, m
        while lo < hi:
            pa = (lo + hi) // 2
            if a[pa] >= b[after - pa - 1]:
                hi = pa
            else:
                lo = pa + 1
        pa = lo
        pb = after - pa

        max_left_a, min_right = a[pa - 1], a[pa]
        max_left_b, min_right_b = b[pb - 1], b[pb]
        return (
            (max(max_left_a, max_left_b) + min(min_right, min_right_b)) / 2
            if not (m + n) % 2
            else max(max_left_a, max_left_b)
        )
