S = [input() for _ in range(3)]
for s in S:
  print 3-sorted(S).index(s)