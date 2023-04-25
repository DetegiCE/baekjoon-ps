for _ in range(int(input())):
    h, m, s = map(int, input().split())
    hd = h*30+m/2+s/120
    md = m*6+s/10
    sd = s*6
    a = [hd, md, sd]
    a.sort()
    d = [a[1]-a[0], a[2]-a[1], 360-a[2]+a[0]]
    d.sort()
    print("%.10f" % d[0])
