N = input()
S = "".join(raw_input() for _ in range(N))

r = S.count("R")
b = S.count("B")
if r>b:
  print "TAKAHASHI"
elif r<b:
  print "AOKI"
else:
  print "DRAW"
