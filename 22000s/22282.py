n = int(input())
a = [int(input()) for _ in range(n)]
a.sort(reverse=True)
a.insert(0, 0)
a.append(0)
for i in range(1, n+2):
    if a[i] < i:
        print(i-1)
        break