c=input()
d=input()
a,b=list(c),list(d)
a.sort()
b.sort()
for i in range(len(a)):
    if a[i] != b[i]:
        print(-1)
        quit()
acur=len(c)-1
bcur=acur
ans=0
while acur >= 0:
    if c[acur] != d[bcur]:
        ans += 1
    else:
        bcur -= 1
    acur-=1
print(ans)