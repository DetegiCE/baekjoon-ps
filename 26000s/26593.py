d = []
while True:
    try:
        a, b, c = input().split()
        b, c = int(b), float(c)
        d.append([b*c, a, b])
    except:
        break
d.sort(key = lambda x: (-x[0], -x[2], x[1]))
for i in d:
    print(f'${i[0]:.2f} - {i[1]}/{i[2]}')