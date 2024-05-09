while True:
    r, g, b = map(int, input().split())
    if r == -1:
        break
    name = ['White','Silver','Gray','Black','Red',
            'Maroon','Yellow','Olive','Lime','Green',
            'Aqua','Teal','Blue','Navy','Fuchsia','Purple']
    red = [255,192,128,0,255,128,255,128,
           0,0,0,0,0,0,255,128]
    green = [255,192,128,0,0,0,255,128,
             255,128,255,128,0,0,0,0]
    blue = [255,192,128,0,0,0,0,0,
            0,0,255,128,255,128,255,128]
    d = []
    for i in range(16):
        d.append([(r-red[i])**2+(g-green[i])**2+(b-blue[i])**2, name[i]])
    d.sort(key=lambda x:x[0])
    print(d[0][1])
