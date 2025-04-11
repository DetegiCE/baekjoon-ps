a, b, c = map(int, input().split())
d = dict()
if a == 0:
    for i in range(1, 11):
        if (c-a*i) % b != 0 or (c-a*i)//b < 1 or (c-a*i)//b > 10:
            continue
        if i in d: d[i].append((c-a*i)//b)
        else: d[i] = [(c-a*i)//b]
else:
    for i in range(1, 11):
        if (c-b*i) % a != 0:
            continue
        if (c-b*i)//a in d: d[(c-b*i)//a].append(i)
        else: d[(c-b*i)//a] = [i]

for i in range(1, 11):
    if i not in d: d[i] = [0]
    for j in d[i]:
        print(j, end=' ')
    print()