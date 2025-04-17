n = int(input())
print(sorted([sorted(list(map(int, input().split())))[n//2] for _ in range(n)])[n//2])