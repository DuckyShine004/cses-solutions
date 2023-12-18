from functools import cache

# n, x = 3, 9
# coins = [2, 3, 5]

# dp = [0] * (x + 1)
# dp[0] = 1
# memo = [True] * n

# for i in range(1, x + 1):
#     out = 0
#     tmp = memo.copy()

#     for j in range(n):
#         k = i - coins[j]

#         if memo[j] and :
#             out += dp[k]
#             tmp[j] = False

#     dp[i] = out


n = 9
coins = [2, 3, 5]

memo = set()
res = 0


@cache
def dp(x, y):
    global res

    print(x, y)

    if x == n:
        return True

    if x > n:
        return False

    for coin in coins:
        if dp(x + coin, coin):
            res += 1

    return False


dp(0, 0)
print(res)
# print(memo)
# print(dp)
# print(dp[x])
