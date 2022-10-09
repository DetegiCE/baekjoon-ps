a = [1,1]
for i in range(1, 32):
    a.append(a[i-1]+a[i])
d, k = map(int, input().split())
af = a[d-3]
bf = a[d-2]
for i in range(1, 100000):
    if (k - af * i) % bf == 0:
        print(i)
        print((k-af*i)//bf)
        quit()
