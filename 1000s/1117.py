def ovrlp(ax1, ax2, ay1, ay2, bx1, bx2, by1, by2):
    xlp = max(min(ax2, bx2) - bx1, 0)
    ylp = max(min(ay2, by2) - by1, 0)
    return xlp * ylp

if __name__ == '__main__':
    w, h, f, c, x1, y1, x2, y2 = map(int, input().split())
    l_each = (f*(h//(c+1))) - ovrlp(0, f, 0, h//(c+1), x1, x2, y1, y2)
    r_each = ((w-f)*(h//(c+1))) - ovrlp(0, w-f, 0, h//(c+1), x1, x2, y1, y2)
    print((l_each+r_each) * (c+1))
