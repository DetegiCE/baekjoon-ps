lk = 'qwertasdfgzxcv'
rk = 'yuiophjklbnm'
ly = [0,0,0,0,0,1,1,1,1,1,2,2,2,2]
ry = [0,0,0,0,0,1,1,1,1,2,2,2]
lx = [0,1,2,3,4,0,1,2,3,4,0,1,2,3]
rx = [5,6,7,8,9,5,6,7,8,4,5,6]
ldx = dict(zip(list(lk), lx))
rdx = dict(zip(list(rk), rx))
ldy = dict(zip(list(lk), ly))
rdy = dict(zip(list(rk), ry))
sl, sr = input().split()
lpx = ldx[sl] if sl in lk else rdx[sl]
rpx = rdx[sr] if sr in rk else ldx[sr]
lpy = ldy[sl] if sl in lk else rdy[sl]
rpy = rdy[sr] if sr in rk else ldy[sr]
t = 0
a = input()
for i in a:
    if i in lk:
        t += abs(lpx-ldx[i]) + abs(lpy-ldy[i])
        lpx = ldx[i]
        lpy = ldy[i]
    else:
        t += abs(rpx-rdx[i]) + abs(rpy-rdy[i])
        rpx = rdx[i]
        rpy = rdy[i]
print(t+len(a))