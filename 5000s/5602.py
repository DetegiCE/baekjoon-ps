if __name__ == '__main__':
    n, m = map(int,input().split())
    klst = [_ for _ in range(1, m+1)]
    vlst = [0 for _ in range(m)]
    d = dict(zip(klst, vlst))
    
    for i in range(n):
        a = list(map(int, input().split()))
        for j in range(m):
            if a[j] == 1:
                d[j+1] += 1
    for k in sorted(d, key=lambda x: (-d[x], x)):
        print(k, end=' ')