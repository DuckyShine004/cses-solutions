from functools import cache

n = 10
coins = [1, 1, 1, 1, 1, 1, 1, 1, 1, 1]
k = sum(coins)

dp = [False] * (k + 1)
dp[0] = True


for coin in coins:
    for j in range(k - coin, -1, -1):
        if dp[j]:
            dp[coin + j] = True

for i in range(k + 1):
    if dp[i]:
        print(i)

print(dp)
