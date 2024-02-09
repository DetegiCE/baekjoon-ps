a = input()
for i in range(len(a), 0, -1):
    for st in range(len(a)-i+1):
        if a[st:i+st] == a[st:i+st][::-1]:
            print(i)
            exit()
