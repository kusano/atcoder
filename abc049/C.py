S = raw_input()

p = len(S)-1
while p>=0:
  if p<2:
    print "NO"
    exit(0)
  if S[p]=="m":
    c = "dream"
  elif S[p]=="e":
    c = "erase"
  elif S[p-2]=="m":
    c = "dreamer"
  else:
    c = "eraser"
  if p>=len(c)-1 and S[p-len(c)+1:p+1]==c:
    p -= len(c)
  else:
    print "NO"
    exit(0)
print "YES"
