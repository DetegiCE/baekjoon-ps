n, m = map(int, input().split())
first = []
for i in range(n):
    r = int(input())
    if i == 0:
        first.append(1)
    else:
        first.insert(r-1, i+1)
second = []
for i in range(m-1, -1, -1):
    r = int(input())
    if i == m-1:
        second.append(first[i])
    else:
        second.insert(r-1, first[i])
for i in range(3):
    print(second[i])