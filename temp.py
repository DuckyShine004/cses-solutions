from functools import cache

n, m = 4, 10

H = [4, 8, 5, 3]
S = [5, 1, 8, 1]

dp = [[0] * (m + 1) for _ in range(n + 1)]

for y in range(1, n + 1):
    for x in range(1, m + 1):
        dp[y][x] = dp[y - 1][x]

        if H[y - 1] <= x:
            dp[y][x] = max(dp[y][x], S[y - 1] + dp[y - 1][x - H[y - 1]])

print(dp[n][m])
