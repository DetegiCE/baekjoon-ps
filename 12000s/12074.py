s = '0'
for i in range(18):
    s = s + '0' + ''.join(list(map(lambda x: '1' if x=='0' else '0', list(s[::-1]))))
for i in range(int(input())):
    k = int(input())
    print(f'Case #{i+1}: {s[k-1]}')
    # print(s)
