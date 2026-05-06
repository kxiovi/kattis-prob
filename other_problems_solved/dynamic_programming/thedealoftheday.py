"""
dp table, where i is the 10 numbers and j is the k. 
e.g. dp table for sample 1
|   | 0 |  1 |  2 | 3  | v[i] |
|:-:|:-:|:--:|:--:|----|------|
| 9 | 1 |  4 |  0 | 0  | 4    |
| 8 | 1 |  4 |  0 | 0  | 0    |
| 7 | 1 | 4  | 0  | 0  | 0    |
| 6 | 1 | 4  | 0  | 0  | 0    |
| 5 | 1 | 4  | 0  | 0  | 0    |
| 4 | 1 | 8  | 16 | 0  | 4    |
| 3 | 1 | 8  | 16 | 0  | 0    |
| 2 | 1 | 8  | 16 | 0  | 0    |
| 1 | 1 | 8  | 16 | 0  | 0    |
| 0 | 1 | 12 | 48 | 64 | 4    |

"""

def main(): 
    v = list(map(int, input().split()))
    k = int(input())

    dp = [[0] * (k+1) for _ in range(11)]
    for i in range(11):
        dp[i][0] = 1  # empty string is a base case and counts as 1 string

    for i in range(9, -1, -1):
        for j in range(1, k+1):
            dp[i][j] = dp[i+1][j] + v[i] * dp[i+1][j-1]
    print(dp[0][k])

if __name__ == '__main__':
    main()
