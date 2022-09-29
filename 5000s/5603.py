if __name__ == '__main__':
    n = int(input())
    a = input()
    for _ in range(n):
        b = ''
        while len(a) > 0:
            b += str(len(a) - len(a.lstrip(a[0])))
            b += a[0]
            a = a.lstrip(a[0])
        a = b
    print(a)
    