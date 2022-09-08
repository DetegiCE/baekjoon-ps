n = -1
m = -1
path = [[] for _ in range(2001)]
vis = [False for _ in range(2001)]

def dfs(cur: int, depth: int):
    if depth == 5:
        print(1)
        quit()
    for j in path[cur]:
        if not vis[j]:
            vis[j] = True
            dfs(j, depth+1)
            vis[j] = False

if __name__ == '__main__':
    n, m = map(int,input().split())
    for i in range(m):
        a, b = map(int,input().split())
        path[a].append(b)
        path[b].append(a)
    for i in range(n):
        for j in range(n):
            vis[j] = False
        vis[i] = True
        dfs(i, 1)
    print(0)