import sys
sys.setrecursionlimit(10**6)

def select(p, r, q):
    global a
    if p == r:
        return a[p]
    t = partition(p, r)
    k = t - p + 1
    if q < k:
        return select(p, t-1, q)
    elif q == k:
        return a[t]
    else:
        return select(t+1, r, q-k)

def partition(p, r):
    global a, k
    x = a[r]
    i = p - 1
    for j in range(p, r):
        if a[j] <= x:
            i += 1
            k -= 1
            a[i], a[j] = a[j], a[i]
            if k == 0:
                print(min(a[i], a[j]), max(a[i], a[j]))
                exit(0)
    if i + 1 != r:
        k -= 1
        a[i+1], a[r] = a[r], a[i+1]
        if k == 0:
            print(min(a[i+1], a[r]), max(a[i+1], a[r]))
            exit(0)
    return i+1

n, q, k = map(int, input().split())
a = list(map(int, input().split()))
select(0, n-1, q)
print(-1)