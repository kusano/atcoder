A,B,C = map(int, raw_input().split())

if A+B==C and A-B!=C:
  print "+"
if A+B!=C and A-B==C:
  print "-"
if A+B==C and A-B==C:
  print "?"
if A+B!=C and A-B!=C:
  print "!"
