n = int(input())
a = [".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",
	 ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.",
	 "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."]
b = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
d = dict(zip(a, b))
for case in range(n):
    e = input().split()
    print(f'Case {case+1}:', end=' ')
    for i in e:
        print(d[i], end='')
    print()
