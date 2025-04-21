n = int(input())
a = sorted([int(input()) for _ in range(n)])
b = [a[i] + a[i+1] for i in range(n-1)]
c = min([b[i+1] - b[i] for i in range(n-2)])
if c % 2 == 0: print(f'{c//2}.0')
else: print(f'{c//2}.5')