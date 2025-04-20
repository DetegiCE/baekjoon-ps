n = int(input())
a = [input() for _ in range(n)]
a.sort(key=lambda x:(len(x), x))
print(*a, sep='\n')