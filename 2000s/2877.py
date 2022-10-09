a = [2]
k = int(input())
for i in range(29):
    a.append(a[-1] * 2)
for i in range(30):
    if k > a[i]:
        k -= a[i]
    else:
        s = bin(k-1)
        print(s[2:].zfill(i+1).replace('0','4').replace('1','7'))
        break