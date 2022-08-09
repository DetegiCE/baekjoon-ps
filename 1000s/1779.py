# WA
import sys
c, a = map(int,input().split())
contractions = dict()
acronyms = dict()
acrocnt = dict()
for _ in range(c):
    s = input()
    slist = s.split(' -> ')
    if slist[0].strip('"') not in contractions:
        contractions[slist[0].strip('"')] = slist[1].strip('"')
    if slist[0].upper().strip('"') not in contractions:
        contractions[slist[0].upper().strip('"')] = slist[1].upper().strip('"')
    if slist[0].strip('"').capitalize() not in contractions:
        contractions[slist[0].strip('"').capitalize()] = slist[1].strip('"').capitalize()
for _ in range(a):
    s = input()
    slist = s.split(' -> ')
    acronyms[slist[0].strip('"')] = slist[1].strip('"')
    acrocnt[slist[0].strip('"')] = 0
    
for line in sys.stdin:
    line = line.strip('\n')
    if line == None:
        break
    if line == '#':
        for k, v in acrocnt.items():
            acrocnt[k] = 0
        print('#')
        continue
    tline = line
    for k, v in contractions.items():
        if k in tline:
            tline = tline.replace(k, v)
    for k, v in acronyms.items():
        if k in tline and acrocnt[k] == 0:
            idx = tline.find(k)
            tline = tline[:idx] + f'{v} ({k})' + tline[idx+len(k):]
            acrocnt[k] = 1
    print(tline)