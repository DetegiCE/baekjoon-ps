while True:
    try:
        n = int(input())
        t = n
        if n == 0:
            print("0 = 0 GSC")
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
            print(t, '=', ans[::-1], 'GSC')
    except:
        break
