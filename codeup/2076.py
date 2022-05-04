scores = list(map(int, input().split()))
score = 0
turn = 1
skip = False
for i in range(len(scores)):
    if skip:
        skip = False
        continue
    if turn <= 9:
        if scores[i] == 10:
            score += 10 + scores[i+1] + scores[i+2]
        elif scores[i] + scores[i+1] == 10:
            score += 10 + scores[i+2]
            skip = True
        else:
            score += scores[i] + scores[i+1]
            skip = True
        turn += 1
    else:
        score += sum(scores[i:])
        break
print(score)
        

