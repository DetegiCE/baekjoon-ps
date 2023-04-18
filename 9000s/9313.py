while True:
    a = int(input())
    if a == -1:
        break
    b = bin(a)[2:]
    c = '0'*(32-len(b)) + b
    c = c[::-1]
    print(int(c, 2))
