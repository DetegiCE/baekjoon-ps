a = list()

if __name__ == '__main__':
    n = int(input())
    a = [0 for _ in range(n+1)]
    a[2] = 1
    a[3] = 2


'''
a[n] = nC1 * a[n-1] + nC2 * a[n-2] + ... + nCn-1 * a[1]
a[n-1]             = n-1C1 * a[n-2] + ... + n-1Cn-2 * a[1]

a[n] - a[n-1]   = nC1 * a[n-1] + n-1C2 * a[n-2] + n-2C3 * a[n-3] + ... + n-1Cn-1 * a[1]
a[n-1] - a[n-2] =                 n-1C1 * a[n-2] + n-2C2 * a[n-3] + ... + n-2Cn-2 * a[1]
...
a[3] - a[2] =                                                       3C1 * a[2] + 3C2 * a[1]
================

a___
_b__
__c_
___d
ab__
_bc_
__cd
a_c_
a__d

'''