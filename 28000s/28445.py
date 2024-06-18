fb, ft = input().split()
mb, mt = input().split()
s = []
for sb in list(set([fb, ft, mb, mt])):
    for st in list(set([fb, ft, mb, mt])):
        s.append([sb, st])
s.sort()
for i in s:
    print(i[0], i[1])
