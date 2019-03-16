N = input()
A = [True]*(N+1)
for _ in range(3):
  t = input()
  if t<=N:
    A[t] = False
T = [101]*(N+1)
T[0] = 0
for i in range(1,N+1):
  if A[i]:
    for j in range(1,4):
      if 0<=i-j:
        T[i] = min(T[i], T[i-j]+1)
if T[N]<=100:
  print "YES"
else:
  print "NO"
