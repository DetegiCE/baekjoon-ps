from collections import Counter

def picks(a, b):
    r = []
    if cnt[a] > 0:
        r.append(a)
    if b != a and cnt[b] > 0:
        r.append(b)
    return r

p = list(map(int, input().split()))
w = list(map(int, input().split()))
cnt = Counter(w)

for i in picks(p[0], p[1]):
    cnt[i] -= 1
    for j in picks(p[2], p[3]):
        cnt[j] -= 1
        for k in picks(p[4], p[5]):
            cnt[k] -= 1
            for l in picks(p[6], p[7]):
                cnt[l] -= 1
                for m in picks(i, j):
                    cnt[m] -= 1
                    for n in picks(k, l):
                        cnt[n] -= 1
                        for o in picks(m, n):
                            cnt[o] -= 1
                            print(o)
                            print(m, n)
                            print(i, j, k, l)
                            exit(0)
                        cnt[n] += 1
                    cnt[m] += 1
                cnt[l] += 1
            cnt[k] += 1
        cnt[j] += 1
    cnt[i] += 1
