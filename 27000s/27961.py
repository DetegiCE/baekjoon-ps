n = int(input())
if n == 0: print(0)
else: print((n-1).bit_length()+1)
