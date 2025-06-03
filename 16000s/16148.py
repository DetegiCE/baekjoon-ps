for i in range(1, int(input()) + 1):
    print(f'Data Set {i}:')
    n = int(input())
    a = list(map(int, input().split()))
    a.sort()
    cnt = 0
    for j in range(n):
        if a[j] > j:
            break
        cnt += 1
    print(cnt)
    print()