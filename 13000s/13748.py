a = input()
for i in range(1, len(a)+1):
    if len(a) % i == 0:
        c = True
        b = a[:i]
        for j in range(i, len(a), i):
            if not c: break
            b = b[-1] + b[:-1]
            if b != a[j:j+i]:
                c = False
        if c:
            print(i)
            break