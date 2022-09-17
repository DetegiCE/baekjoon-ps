def sol():
    a = list(map(int,input().split()))
    cnt = [0] * 9
    for i in range(1, len(a), 2):
        cnt[a[i+1]] += 1
    print(max(cnt))
    
if __name__ == '__main__':
    for _ in range(int(input())):
        sol()