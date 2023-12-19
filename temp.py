from functools import cache

# n = 4
# t = 10

# books = [4, 8, 5, 3]
# pages = [5, 12, 8, 1]


# @cache
# def dp(x, y):
#     if y >= n - 1:
#         return x

#     print(x, y)

#     out = 0

#     for i in range(y + 1, n):
#         if x + books[i] <= t:
#             out = max(out, dp(x + pages[i], i))

#     return out


# res = dp(pages[0], 0)

# print(res)

n = 100
t = 1000000

s = "27 69 68 13 1 63 28 44 45 67 57 11 8 85 42 20 32 77 39 52 70 24 4 79 7 15 54 88 51 73 89 66 48 56 47 18 2 30 21 49 74 9 99 83 55 95 62 90 22 31 71 98 43 75 25 16 12 64 61 38 40 26 3 96 41 86 5 14 91 33 78 50 23 84 94 36 46 97 53 81 65 34 93 59 6 35 72 10 82 60 19 92 29 87 76 100 80 17 58 37"
coins = list(map(int, s.split(" ")))

# print(coins)

# @cache
# def dp(x, y):
#     if x == n:
#         return 1

#     if x > n or y >= t:
#         return 0

#     l = dp(x + coins[y], y)
#     r = dp(x, y + 1)

#     return l + r

MOD = 1000000007
dp = [0] * (t + 1)
dp[0] = 1

for coin in coins:
    for x in range(coin, t + 1):
        dp[x] += dp[x - coin] % MOD

# print(dp)
print(dp[t])
# res = dp(0, 0)
# print(res)
