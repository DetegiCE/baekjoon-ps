a, b = map(int, input().split())
a, b = min(a, b), max(a, b)
if a == b:
    print(1)
    exit()
div = set()
for i in range(1, int((b-a)**0.5)+1):
    if (b-a) % i == 0:
        div.add(i)
        div.add((b-a)//i)
div = sorted(list(div))
clcm = 1e36
cn = 1e36
for d in div:
    n = d - (a % d)
    if n > 0:
        l = (a+n)*(b+n)//d
        if clcm > l:
            clcm = l
            cn = n
print(cn)
