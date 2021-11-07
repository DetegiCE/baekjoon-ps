n = int(input())
a = list(map(int, input().split()))
for i in a:
    if int(i**0.5)**2 == i: print(1, end=' ')
    else: print(0, end=' ')
