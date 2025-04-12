a, b, n, m, k = map(int, input().split())
mx = max(a, b)
# dx = [a,a,-a,-a,b,b,-b,-b]
# dy = [b,-b,b,-b,a,-a,a,-a]

# for i in range(n):
#     for j in range(m):
#         c = 0
#         for l in range(8):
#             nx = i+dx[l]
#             ny = j+dy[l]
#             if 0 <= nx < n and 0 <= ny < m:
#                 c += 1
#         print(c, end=' ')
#     print()

if k in [0, 1, 5, 7]:
    print(0)
elif k == 8:
    print(max(0, (n-mx*2) * (m-mx*2)))
elif k == 6:
    print(max(0, abs(a-b) * (n+m-mx*4) * 2))
elif k == 4:
    k41 = max(0, n-(n-mx*2)-abs(a-b)*2)
    k42 = max(0, m-(m-mx*2)-abs(a-b)*2)
    k43 = abs(a-b) ** 2
    print(max(0, k41 * (m-mx*2) + k42 * (n-mx*2) + k43 * 4))
elif k == 2:
    k21 = max(0, m-(m-mx*2)-abs(a-b)*2)
    k22 = max(0, n-(n-mx*2)-abs(a-b)*2)
    print(max(0, k21*k22))
elif k == 3:
    k41 = max(0, n-(n-mx*2)-abs(a-b)*2)
    k42 = max(0, m-(m-mx*2)-abs(a-b)*2)
    k43 = abs(a-b) ** 2
    k21 = max(0, m-(m-mx*2)-abs(a-b)*2)
    k22 = max(0, n-(n-mx*2)-abs(a-b)*2)
    c8 = max(0, (n-mx*2) * (m-mx*2))
    c6 = max(0, abs(a-b) * (n+m-mx*4) * 2)
    c4 = max(0, k41 * (m-mx*2) + k42 * (n-mx*2) + k43 * 4)
    c2 = max(0, k21*k22)
    print(max(0, n*m-c8-c6-c4-c2))
else:
    print(0)