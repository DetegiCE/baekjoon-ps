n = int(input())
a = list(map(int, input().split()))
b, c = map(int, input().split())
print(sum(list(map(lambda x: max((x-b+c-1)//c, 0)+1, a))))