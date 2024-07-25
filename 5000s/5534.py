n = int(input())
a = input()
ans = 0
for _ in range(n):
    flg = False
    b = input()
    for i in range(len(b)-len(a)+1):
        if b[i] != a[0]: continue
        for j in range(i+1, len(b)):
            if b[j] != a[1]: continue
            spc = j - i
            cur = 2
            ri = j + spc

            cnt = 2
            while True:
                if ri >= len(b) or cnt == len(a):
                    break
                if b[ri] != a[cur]:
                    cur += 1
                    break
                cur += 1
                cnt += 1
                ri += spc
            
            if cnt == len(a):
                flg = True
                ans += 1
                break
        if flg:
            break
print(ans)