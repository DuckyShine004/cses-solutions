from functools import cache

n = 1000
MOD = 1000000007


# @cache
# def dp(x):
#     if x == n:
#         return 1

#     if x > n:
#         return 0

#     out = 0

#     for i in range(1, 7):
#         out += dp(x + i)

#     return out % MOD


# res = dp(0)

dp = [0] * (n + 1)
dp[0] = 1

for x in range(1, n + 1):
    out = 0

    for i in range(1, 7):
        if x - i >= 0:
            out += dp[x - i]

    dp[x] = out % MOD


print(dp[n])
# dp = [[0] * 6 for _ in range(n)]

# for y in range(n):
#     out = 0

#     for i in range(1, 7):
#         ...

#     dp[]


# print(res)
