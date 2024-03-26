t = int(input())
for _ in range(t):
    a = list(map(int, input().split()))[1:]
    n = len(a)
    d = {}
    for i in a:
        if i in d: d[i] += 1
        else: d[i] = 1
    mx = max(d.values())
    if mx > n//2:
        for i in d:
            if d[i] == mx:
                print(i)
                break
    else:
        print('SYJKGW')
