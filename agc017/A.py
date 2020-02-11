N, P = map(int, raw_input().split())
A = map(int, raw_input().split())

if all(a%2==0 for a in A):
  if P==0:
    print 2**N
  else:
    print 0
else:
  print 2**N/2
