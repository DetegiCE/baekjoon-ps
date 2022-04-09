a, b = sorted(list(map(int, input().split())))
print(0 if a == b else b-a-1)
print(' '.join(list(map(str, range(a+1, b)))))