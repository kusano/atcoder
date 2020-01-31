N, M = map(int, raw_input().split())
f = [input()-1 for _ in range(N)]

mod = 1000000007
T = [0]*N
S = [0]*(N+1) # S[i] = sum(T[:i])
P = [-1]*M
x = -1

for i in range(N):
  if P[f[i]]!=-1:
    x = max(x, P[f[i]])
  P[f[i]] = i

  if x==-1:
    T[i] = (1+S[i])%mod
  else:
    T[i] = (S[i]-S[x])%mod

  S[i+1] = (S[i]+T[i])%mod
print T[N-1]
