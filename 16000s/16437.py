import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

par = [0, 0]
pop = [0, 0]
lnk = [[]]

def bfs(cur):
    if len(lnk[cur]) == 0:
        return 0 if pop[cur]<0 else pop[cur]
    s = 0
    for nxt in lnk[cur]:
        s += bfs(nxt)
    if pop[cur] > 0:
        return s + pop[cur]
    else:
        if abs(pop[cur]) >= s:
            pop[cur] += s
            return 0
        else:
            t = pop[cur]
            pop[cur] = 0
            return s + t

n = int(input())
for i in range(n):
    lnk.append([])
for i in range(2, n+1):
    a, p, l = input().split()
    p, l = int(p), int(l)
    par.append(l)
    pop.append(p * (-1 if a == 'W' else 1))
    lnk[l].append(i)

print(bfs(1))
