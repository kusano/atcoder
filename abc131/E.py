N, K = map(int, raw_input().split())

if K<=(N-1)*(N-2)/2:
  E = []
  for i in range(N-1):
    for j in range(i):
      E += [(j, i)]
  E = E[:(N-1)*(N-2)/2-K]
  for i in range(N-1):
    E += [(i, N-1)]
  print len(E)
  for e in E:
    print e[0]+1, e[1]+1
else:
  print "-1"
