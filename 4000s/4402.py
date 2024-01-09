d1 = 'BFPV'
d2 = 'CGJKQSXZ'
d3 = 'DT'
d4 = 'L'
d5 = 'MN'
d6 = 'R'
while True:
    try:
        a = input()
        ans = ''
        for i in a:
            if i in d1:
                ans += '1'
            elif i in d2:
                ans += '2'
            elif i in d3:
                ans += '3'
            elif i in d4:
                ans += '4'
            elif i in d5:
                ans += '5'
            elif i in d6:
                ans += '6'
            else:
                ans += '0'
        for i in range(1, 7):
            while str(i)+str(i) in ans:
                ans = ans.replace(str(i)+str(i), str(i))
        ans = ans.replace('0','')
        print(ans)
    except:
        break
