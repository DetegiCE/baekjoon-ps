b = []
a = []
while True:
    try:
        b.append(input())
    except:
        for i in range(len(b[0])):
            a.append(0)
        for i in b:
            for j in range(len(b[0])):
                a[j] += int(i[j])
        for i in a:
            print(i%10, end='')
        break
