S = raw_input()

for i in range(26):
  c = chr(ord('a')+i)
  if c not in S:
    print c
    break
else:
  print "None"
