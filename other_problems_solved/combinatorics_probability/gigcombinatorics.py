MOD = 10**9 + 7

def main():
    n = int(input())
    hype_list = list(map(int, input().split()))
    ans = 0
    
    # maximo_two = n+1
    # powers2 = [1] * (maximo_two)
    # for i in range(1, maximo_two):
    #     powers2[i] = (powers2[i-1] * 2) % MOD


    sub = 0
    count3 = 0
    count2 = 0
    count1 = 0
    for r in hype_list:
        if r == 1:
            count1 = (count1 + 1) % MOD
        elif r == 2:
            sub = (count1 + sub * 2) % MOD
        elif r == 3:
            ans = (ans + sub) % MOD

    print(ans)


if __name__ == "__main__":
    main()
    
