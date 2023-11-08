while True:
    a = int(input())
    if a == 0:
        break
    b = input()
    for i in range(1, len(b)//a, 2):
        b = b[:i*a] + b[i*a:(i+1)*a][::-1] + b[((i+1)*a):]
    for i in range(a):
        print(b[i::a], end='')
    print()
