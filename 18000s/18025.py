n = int(input())
a = list(map(int, input().split()))
b = []
for i in range(n-2):
    b.append((max(a[i], a[i+2]), i+1))
print(min(b)[1], min(b)[0])
