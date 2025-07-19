while True:
    a = input().strip()
    if a == "0 0 0":
        break
    a = list(map(int, a.split()))
    a.sort()
    if a[0] == a[1] == a[2]:
        s = a[0]
        if s < 13:
            print(f"{s + 1} {s + 1} {s + 1}")
        else:
            print("*")
    elif a[0] == a[1] or a[1] == a[2]:
        if a[0] == a[1]:
            p = a[0]
            kc = a[2]
        else:
            p = a[1]  
            kc = a[0]
        found = False
        if kc < 13:
            for k in range(kc + 1, 14):
                if k != p:
                    ans = [p, p, k]
                    ans.sort()
                    print(f"{ans[0]} {ans[1]} {ans[2]}")
                    found = True
                    break
        if not found:
            for p in range(p + 1, 14):
                for k in range(1, 14):
                    if k != p:
                        ans = [p, p, k]
                        ans.sort() 
                        print(f"{ans[0]} {ans[1]} {ans[2]}")
                        found = True
                        break
                if found:
                    break
        if not found:
            print("1 1 1")
    else:
        print("1 1 2")
