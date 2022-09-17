def sol():
    a = input()
    pos = len(a)-1
    for i in range(len(a)-1, -1, -1):
        if ord(a[i]) > ord(a[i-1]):
            pos = i
            break
    print(f'The longest decreasing suffix of {a} is {a[pos:]}')

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        sol()