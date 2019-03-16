sx, sy, tx, ty = map(int, raw_input().split())
w = tx-sx
h = ty-sy
print "U"*h+"R"*w+"D"*h+"L"*w+"L"+"U"*(h+1)+"R"*(w+1)+"D"+"R"+"D"*(h+1)+"L"*(w+1)+"U"
