a,b,c=map(int,input().split(' : '))
d,e,f=map(int,input().split(' : '))
d+=24*(a>d or (a==d and b>e) or (a==d and b==e and c>f))
print((d-a)*3600+(e-b)*60+(f-c))