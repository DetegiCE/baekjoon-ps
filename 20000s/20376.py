s = set()
while True:
    try:
        a = input()
        s.add(a[11:])
    except:
        break
print(len(s))