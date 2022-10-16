for _ in range(int(input())):
    a, b = input().split()
    c = a.count(b)
    print(c + len(a)-len(b)*c)