t = [1, 1, 2, 5]
n = int(input())
for i in range(4, n+1):
    s = 0
    for j in range(i):
        s += t[j] * t[i-j-1]
    t.append(s)
print(t[n])