a = [0] * 10
n, m = map(int, input().split())
for i in range(n, m+1):
    for j in str(i):
        a[ord(j)-48] += 1
for i in a:
    print(i, end=' ')