a = input()
c = [[0, 0] for _ in range(26)]
for i in range(52):
    cur = ord(a[i]) - 65
    if c[cur][0] == 0: c[cur][0] = i+1
    else: c[cur][1] = i+1
b = 0
for i in range(26):
    for j in range(26):
        if c[i][0] < c[j][0] and c[j][0] < c[i][1] and c[i][1] < c[j][1]: 
            b += 1
print(b)