p = ['Franklin', 'Grant', 'Jackson', 'Hamilton', 'Lincoln', 'Washington']
q = [100, 50, 20, 10, 5, 1]
d = dict(zip(p, q))
for _ in range(int(input())):
    print('$',sum(map(lambda x: d[x], input().split())), sep='')
