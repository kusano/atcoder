A, B, C = map(int, raw_input().split())

for i in range(B):
  if i*A%B==C:
    print "YES"
    break
else:
  print "NO"
