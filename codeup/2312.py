n, a, b = map(int, input().split())
day1 = set(map(int, input().split()))
day2 = set(map(int, input().split()))
print(int(n)-len(day1.union(day2)), len(day1.intersection(day2)))