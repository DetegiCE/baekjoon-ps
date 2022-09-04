from sys import stdin as s

class Score:
    def __init__(self, name, kor, eng, math):
        self.name = name
        self.kor = kor
        self.eng = eng
        self.math = math
        
    def __lt__(self, other):
        if self.kor == other.kor:
            if self.eng == other.eng:
                if self.math == other.math:
                    return self.name < other.name
                else:
                    return self.math > other.math
            else:
                return self.eng < other.eng
        else:
            return self.kor > other.kor
        

n=int(s.readline())
scores = []
for i in range(n):
    n,k,e,m=s.readline().split()
    k,e,m=map(int,(k,e,m))
    scores.append(Score(n,k,e,m))
scores = sorted(scores)
for s in scores:
    print(s.name)
