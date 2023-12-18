from functools import cache

# n = 9
# coins = [2, 3, 5]


# @cache
# def dp(x):
#     if x == n:
#         return 1

#     if x > n:
#         return 0

#     out = 0

#     for coin in coins:
#         out += dp(x + coin)

#     return out

# res = dp(0)

# print(res)


n, x = 3, 9
coins = [2, 3, 5]

dp = [0] * (x + 1)
dp[0] = 1

for i in range(1, x + 1):
    k = 0

    for coin in coins:
        if i - coin >= 0:
            k += dp[i - coin]

    dp[i] = k

print(dp[x])
