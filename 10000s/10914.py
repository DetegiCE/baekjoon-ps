n = int(input())
a = input().split()
for w in a:
    for i in range(0, len(w), 2):
        try:
            a1 = ord(w[i]) - 97
            a2 = ord(w[i+1]) - 97
            print(chr((a1+a2-n)%26+97), end='')
        except:
            break
    print(' ', end='')
