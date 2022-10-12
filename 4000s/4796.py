c = 0
while True:
    c += 1
    l, p, v = map(int, input().split())
    if l == p == v == 0:
        break
    print(f'Case {c}:', end=' ')
    print((v // p) * l + min(v % p, l))