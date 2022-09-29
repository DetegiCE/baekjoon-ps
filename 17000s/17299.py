n = -1
a = []
cnt = []
ngf = []
st = []

if __name__ == '__main__':
    n = int(input())
    a = list(map(int,input().split()))
    cnt = [0] * (1000001)
    ngf = [-1] * (n+1)
    for i in a:
        cnt[i] += 1
    for i in range(n):
        while len(st) > 0 and cnt[a[st[-1]]] < cnt[a[i]]:
            ngf[st[-1]] = a[i]
            st.pop()
        st.append(i)
    for i in range(n):
        print(ngf[i], end=' ')