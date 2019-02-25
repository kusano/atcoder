X = raw_input()

while len(X)>0:
  if X[-2:]=="ch":
    X = X[:-2]
  elif X[-1] in "oku":
    X = X[:-1]
  else:
    print "NO"
    exit(0)
print "YES"
