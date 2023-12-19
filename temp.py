from functools import cache

x = 9722
y = str(x)


# @cache
# def dp(x, y):
#     if x == 0:
#         return 0

#     out = float("inf")

#     # print(x, y)

#     for digit in y:
#         k = x - int(digit)

#         if digit > "0" and k >= 0:
#             out = min(out, dp(k, str(k)) + 1)

#     return out


dp = [float("inf")] * (x + 1)
dp[0] = 0

for i in range(1, x + 1):
    k = str(i)

    for digit in k:
        a = i - int(digit)

        if a >= 0:
            dp[i] = min(dp[i], dp[a] + 1)


# print(dp(x, y))

print(dp)
