r = 1
a = 2
k = 1
s = 1
t = 1
n = int(input())
b = input()
for i in range(n):
    if b[i] == 'R': r -= 1
    if b[i] == 'A': a -= 1
    if b[i] == 'K': k -= 1
    if b[i] == 'S': s -= 1
    if b[i] == 'T': t -= 1
    if r <= 0 and a <= 0 and k <= 0 and s <= 0 and t <= 0:
        print(i+1)
        break
