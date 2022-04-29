m = int(input())
left = list()
right = list()
same = list()
a = map(int, input().split())
n = int(input())
for i in a:
    if i < n:
        left.append(i)
    elif i > n:
        right.append(i)
    else:
        same.append(i)
for i in left:
    print(i, end=' ')
for i in same:
    print(i, end=' ')
for i in right:
    print(i, end=' ')