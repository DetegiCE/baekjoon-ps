n = int(input())
a = list(map(int, input().split()))
a.sort(reverse=True)
a.insert(0, 0)
a.append(0)
for i in range(1, n+2):
    if a[i] < i:
        print(i-1)
        break