c = 0
n = int(input())
p = list(map(int, input().split()))
for i in range(2, n+1):
    for j in range(n-i+1):
        s = sum(p[j:i+j])
        if s % i == 0 and s // i in p[j:i+j]:
            c += 1
print(c+n)
