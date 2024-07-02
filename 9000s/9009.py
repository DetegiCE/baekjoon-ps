fibo = [1, 1]

def f(n):
    lef = n
    ans = []
    for i in fibo[::-1]:
        if lef >= i:
            ans.append(i)
            lef -= i
    for i in ans[::-1]:
        print(i, end=' ')
    print()

for _ in range(50):
    fibo.append(fibo[-1] + fibo[-2])

for _ in range(int(input())):
    f(int(input()))