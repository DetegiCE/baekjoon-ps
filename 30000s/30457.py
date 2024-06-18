n = int(input())
a = list(map(int, input().split()))
b = list(set(a))
for i in b:
    for j in range(len(a)):
        if a[j] == i:
            a[j] = 0
            break
c = list(set(a))
print(len(b)+len(c)-1)
