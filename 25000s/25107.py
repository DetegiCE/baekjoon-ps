n, m, k = map(int, input().split())
cmd = input()
mp = []
for i in range(n):
    mp.append(list(input()))
for c in cmd:
    if c == 'D':
        for loop in range(n):
            for i in range(n-1, 0, -1):
                for j in range(m):
                    if mp[i][j] == '.' and mp[i-1][j] != '.':
                        mp[i][j] = mp[i-1][j]
                        mp[i-1][j] = '.'
    if c == 'U':
        for loop in range(n):
            for i in range(n-1):
                for j in range(m):
                    if mp[i][j] == '.' and mp[i+1][j] != '.':
                        mp[i][j] = mp[i+1][j]
                        mp[i+1][j] = '.'
    if c == 'L':
        for loop in range(m):
            for i in range(m-1):
                for j in range(n):
                    if mp[j][i] == '.' and mp[j][i+1] != '.':
                        mp[j][i] = mp[j][i+1]
                        mp[j][i+1] = '.'
    if c == 'R':
        for loop in range(m):
            for i in range(m-1, 0, -1):
                for j in range(n):
                    if mp[j][i] == '.' and mp[j][i-1] != '.':
                        mp[j][i] = mp[j][i-1]
                        mp[j][i-1] = '.'
for i in range(n):
    print(''.join(mp[i]))
                        
                    
                    
