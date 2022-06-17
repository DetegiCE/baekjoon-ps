from datetime import datetime, timedelta
t=int(input())
for _ in range(t):
    y,m=map(int,input().split())
    a=datetime(y,m,m)
    print((a+timedelta(days=-m)).strftime("%Y %-m %-d"))
