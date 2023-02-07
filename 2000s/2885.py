from math import log2, ceil
k = int(input())
c = bin(k)[2:].rfind('1')
print(2**ceil(log2(k)), 0 if c==0 else c+1)
