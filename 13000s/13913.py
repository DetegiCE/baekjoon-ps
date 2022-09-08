import sys
sys.setrecursionlimit(10**5)

n = -1
k = -1
vis = [-1 for _ in range(200001)]
q = []
r = []

def backtrack(cur: int, cnt: int):
    global r
    if cur == n:
        for i in r[::-1]:
            print(i, end=' ')
        return
    if vis[cur-1] == cnt - 1:
        r.append(cur-1)
        backtrack(cur-1, cnt-1)
    elif vis[cur+1] == cnt - 1:
        r.append(cur+1)
        backtrack(cur+1, cnt-1)
    elif cur % 2 == 0 and vis[cur//2] == cnt - 1:
        r.append(cur//2)
        backtrack(cur//2, cnt-1)
        
if __name__ == '__main__':
    n, k = map(int,input().split())
    if n == k:
        print('0\n'+str(n))
        quit()
    if n > k:
        print(n-k)
        for i in range(n, k-1, -1):
            print(i, end=' ')
        quit()
    q.append(n)
    vis[n] = 0
    while len(q) > 0:
        qf = q[0]
        q.pop(0)
        if qf+1 < 200001 and vis[qf+1] == -1:
            if qf+1 == k:
                print(vis[qf] + 1)
                r.append(k)
                backtrack(k, vis[qf] + 1)
                quit()
            q.append(qf+1)
            vis[qf+1] = vis[qf] + 1
        if qf > 0 and vis[qf-1] == -1:
            if qf-1 == k:
                print(vis[qf] + 1)
                r.append(k)
                backtrack(k, vis[qf] + 1)
                quit()
            q.append(qf-1)
            vis[qf-1] = vis[qf] + 1
        if qf*2 < 200001 and vis[qf*2] == -1:
            if qf*2 == k:
                print(vis[qf] + 1)
                r.append(k)
                backtrack(k, vis[qf] + 1)
                quit()
            q.append(qf*2)
            vis[qf*2] = vis[qf] + 1