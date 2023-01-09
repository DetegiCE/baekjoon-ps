from sys import stdin
input = stdin.readline
n = int(input())
room = [0 for _ in range(200001)]
cnt = 0
for _ in range(n):
    a, b = map(int, input().split())
    if room[a] == b:
        cnt += 1
        room[a] = b
    else:
        room[a] = b
for i in range(200001):
    if room[i] == 1:
        cnt += 1
print(cnt)
