A,B,C,D = map(int, raw_input().split())
if A+B>C+D:
  print "Left"
elif A+B==C+D:
  print "Balanced"
else:
  print "Right"
