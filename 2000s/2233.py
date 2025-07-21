n = int(input())
a = input()
x, y = map(int, input().split())
st = []
x -= 1
y -= 1
xz, yz = -1, -1
for i in range(n*2):
    if a[i] == '0':
        if i == x:
            xz = i
        if i == y:
            yz = i
        st.append(i)
    else:
        if i == x:
            xz = st[-1]
        if i == y:
            yz = st[-1]
        st.pop()
xt = []
yt = []
import copy
for i in range(n*2):
    if a[i] == '0':
        st.append(i)
        if i == xz:
            xt = copy.deepcopy(st)
        if i == yz:
            yt = copy.deepcopy(st)
    else:
        st.pop()

g = -1
for i in range(min(len(xt), len(yt))):
    if xt[i] == yt[i]:
        g = xt[i]
h = -1
for i in range(n*2):
    if a[i] == '0':
        st.append(i)
    else:
        if st[-1] == g:
            h = i
        st.pop()
print(g+1, h+1)