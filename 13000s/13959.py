d = int(input())
r = int(input())
t = int(input())
ra = 4
ta = 3
rc = 0
tc = 0
s = r + t
while d+ta > ra:
    rc += ra
    ra += 1
while rc+tc < s:
    rc += ra
    tc += ta
    ra += 1
    ta += 1
print(r-rc)