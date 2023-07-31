s,p = map(int, input().split())
b = input()
a,c,g,t = map(int, input().split())
y = 0
for i in range(p):
    if b[i] == 'A': a -= 1
    if b[i] == 'C': c -= 1
    if b[i] == 'G': g -= 1
    if b[i] == 'T': t -= 1
for i in range(s-p):
    if a <= 0 and c <= 0 and g <= 0 and t <= 0:
        y += 1
    if b[i] == 'A': a += 1
    if b[i] == 'C': c += 1
    if b[i] == 'G': g += 1
    if b[i] == 'T': t += 1
    if b[i+p] == 'A': a -= 1
    if b[i+p] == 'C': c -= 1
    if b[i+p] == 'G': g -= 1
    if b[i+p] == 'T': t -= 1
if a <= 0 and c <= 0 and g <= 0 and t <= 0:
    y += 1
print(y)
