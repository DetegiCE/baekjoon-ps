l = int(input())
s = sorted(map(int, input().split()))
a = int(input())
if a in s:
    print(0)
elif a < s[0]:
    print((s[0]-1-a)*a + a - 1)
else:
    mnv = mxv = 0
    for i in range(l):
        if s[i] < a < s[i+1]:
            mnv = s[i] + 1
            mxv = s[i+1] - 1
            break
    print((mxv-a)*(a-mnv+1) + a - mnv)