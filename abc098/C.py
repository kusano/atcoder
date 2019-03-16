N = input()
S = raw_input()

L = [0]*N
if S[0]=="W":
  L[0] = 1
for i in range(1, N):
  L[i] = L[i-1] + (S[i]=="W")

R = [0]*N
if S[-1]=="E":
  R[-1] = 1
for i in range(N-2, -1, -1):
  R[i] = R[i+1] + (S[i]=="E")

ans = N
for i in range(N):
  t = 0
  if i>0:
    t += L[i-1]
  if i<N-1:
    t += R[i+1]
  ans = min(ans, t)
print ans
