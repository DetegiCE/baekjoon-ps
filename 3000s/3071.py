for _ in range(int(input())):
    n = int(input())
    if n == 0:
        print("0")
    else:
        ans = ""
        while n != 0:
            r = n % 3
            n //= 3
            if r == 2:
                ans += "-"
                n += 1
            else:
                ans += str(r)
        print(ans[::-1])
