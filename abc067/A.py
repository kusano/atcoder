A,B = map(int, raw_input().split())
if A%3==0 or B%3==0 or (A+B)%3==0:
  print "Possible"
else:
  print "Impossible"
