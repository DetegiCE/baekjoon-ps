for tc in range(1, int(input())+1):
    print(f'Case {tc}: ', end='')
    n = int(input())
    a = list(map(int, input().split()))
    s = set(a)
    for i in range(n):
        if a[i] in s:
            s.remove(a[i])
        if not s:
            print(i+1)
            break
    if s:
        print(n)