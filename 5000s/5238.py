def sol():
    a = list(map(int,input().split()))
    for i in range(3, a[0]):
        if a[i] != a[i-1] +a[i-2]:
            print('NO')
            return
    print('YES')
    
if __name__ == '__main__':
    for _ in range(int(input())):
        sol()