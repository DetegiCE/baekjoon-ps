import sys
input = sys.stdin.read
data = input().splitlines()

results = []
i = 0

while i < len(data):
    line = data[i]
    i += 1
    m, nmin, nmax = map(int, line.split())
    
    if m == 0 and nmin == 0 and nmax == 0:
        break
    
    scores = []
    for _ in range(m):
        scores.append(int(data[i]))
        i += 1
        
    max_gap = -1
    best_n = -1
    
    for n in range(nmin, nmax + 1):
        gap = scores[n-1] - scores[n]
        if gap > max_gap or (gap == max_gap and n > best_n):
            max_gap = gap
            best_n = n
    
    results.append(best_n)

for result in results:
    print(result)
