n = int(input())
a = [input() for _ in range(n)]
c = 0
for i in range(n):
    for j in range(i+1, n):
        for k in range(1, min(len(a[i]), len(a[j]))+1):
            if a[i][-k:] == a[j][:k] or a[i][:k] == a[j][-k:]:
                c += 1
                break
print(c)