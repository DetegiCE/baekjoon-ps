for _ in range(int(input())):
    n, m = map(int, input().split())
    a = []
    for i in range(n):
        a.append(input())
    for i in range(n):
        print(a[i][::-1])
