N, M = map(int, raw_input().split())

if M<2*N:
  print -1, -1, -1
elif M<=3*N:
  t = M-2*N
  print N-t, t, 0
elif M<=4*N:
  t = M-3*N
  print 0, N-t, t
else:
  print -1, -1, -1
