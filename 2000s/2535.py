n = int(input())
a = []
for _ in range(n):
    a.append(list(map(int, input().split())))
a.sort(key=lambda x: -x[2])
print(*a[0][:2])
print(*a[1][:2])
if a[0][0] == a[1][0]:
    c = 2
    while True:
        if a[0][0] == a[1][0] == a[c][0]:
            c += 1   
            continue
        else:
            break
    print(*a[c][:2])
else:
    print(*a[2][:2])
