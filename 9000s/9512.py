n = int(input())
w = dict()
for _ in range(n):
    a = input().split()
    for i in a[1:]:
        w[i.lower()] = a[0]
input()
while True:
    try:
        a = input().lower()
        for i in '.,!;?()[]{}*&@#$%^=_+\\|:"<>~`/0123456789':
            a = a.replace(i, ' ')
        a = a.split()
        for i in a:
            if i in w:
                print(w[i])
                break
    except:
        break
