a = [1, 1]
for i in range(251):
    a.append(a[-1]+2*a[-2])
while True:
    try:
        n = int(input())
        print(a[n])
    except:
        break