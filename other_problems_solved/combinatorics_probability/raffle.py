# resources: 
#   iteratively calculate nCr: https://www.geeksforgeeks.org/dsa/program-calculate-value-ncr/
#   nCR iterative: https://stackoverflow.com/questions/11809502/which-is-better-way-to-calculate-ncr 

import math
def iterative(n, k):
    if k == n:
        return 0.0
    if k > n:
        return 0.0
    k = min(k, n-k)
    # ans = 1.0
    ans = 0.0
    for i in range(1, k+1):
        # ans = (n - k + i) / i * ans
        ans = math.log(n - k + i) - math.log(i) + ans
    return ans

def main():
    n, z = map(int, input().split())

    # constant = iterative(n, z-1)
    # kIsOne = 1.0 / iterative(n+1, z)
    # ans = constant * kIsOne

    constant = iterative(n, z-1)
    log_ans = constant - iterative(n+1, z)
    ans = math.exp(log_ans)
    curr = ans

    for k in range(2, n + z + 100000000):
        # w = ((k+1) * (n+k-z+1)) / (k * (n+k+1))
        # w = (k / (k-1)) * ((n + k - z) / (n + k))
        # curr *= w
        log_curr = math.log(k) + constant - iterative(n+k, z)
        curr = math.exp(log_curr)

        if curr > ans:
            ans = curr
        else:
            return ans
    return ans


if __name__ == "__main__":
    ans = main()
    print(f"{ans:.10f}")
