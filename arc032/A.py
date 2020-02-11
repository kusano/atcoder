n = input()

n = n*(n+1)/2
if n==1:
  print "BOWWOW"
  exit(0)
f = 2
while f*f<=n:
  if n%f==0:
    print "BOWWOW"
    exit(0)
  f += 1
print "WANWAN"
