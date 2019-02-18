X,A,B = map(int, raw_input().split())
if A>=B:
  print "delicious"
elif B-A<=X:
  print "safe"
else:
  print "dangerous"
