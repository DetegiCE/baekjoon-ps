a = [0,1,1]
for i in range(1002):
    a.append(a[-1] + 2*a[-2])
while True:
    try:
        n = int(input()) - 1
        print(a[n])
    except:
        break