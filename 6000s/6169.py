m, t, u, f, d = map(int, input().split())
s = []
for _ in range(t):
    a = input()
    if a == 'u': s.append(1)
    elif a == 'd': s.append(-1)
    else: s.append(0)

a = 0
b = 0
for i in range(t):
    if s[i] != 0:
        if a + u + d <= m:
            a += u + d
            b += 1
        else: break
    else:
        if a + 2 * f <= m:
            a += 2 * f
            b += 1
        else: break
print(b)