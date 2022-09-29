if __name__ == '__main__':
    a, b = map(int, input().split())
    input()
    c = list(map(int, input().split()))
    cs = 0
    for i in c:
        cs *= a
        cs += i
    d = []
    while cs > 0:
        d.append(cs % b)
        cs //= b
    for i in d[::-1]:
        print(i, end=' ')
    