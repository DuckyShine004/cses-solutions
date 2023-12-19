from functools import cache
import math

arr = [1, 3, 4, 5, 6, 7, 8]

l = 0
r = len(arr) - 1

target = 4

while l < r:
    k = l + ((r - l) // 2)

    if arr[k] < target:
        l = k + 1
    else:
        r = k

print(l)
