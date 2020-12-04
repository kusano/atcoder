H, W, N = map(int, raw_input().split())
sr, sc = map(int, raw_input().split())
sr -= 1
sc -= 1
S = raw_input()
T = raw_input()

L = [-1]*N
R = [W]*N
U = [-1]*N
D = [H]*N

if S[-1]=="L":
  L[-1] = 0
if S[-1]=="R":
  R[-1] = W-1
if S[-1]=="U":
  U[-1] = 0
if S[-1]=="D":
  D[-1] = H-1

ans = "YES"

for i in range(N-1)[::-1]:
  L[i] = L[i+1]
  R[i] = R[i+1]
  U[i] = U[i+1]
  D[i] = D[i+1]
  if S[i]=="L" and (T[i]!="R" or L[i]<0):
    L[i] += 1
  if S[i]!="L" and T[i]=="R":
    L[i] = max(L[i]-1, -1)
  if S[i]=="R" and (T[i]!="L" or R[i]>=W):
    R[i] -= 1
  if S[i]!="R" and T[i]=="L":
    R[i] = min(R[i]+1, W)
  if S[i]=="U" and (T[i]!="D" or U[i]<0):
    U[i] += 1
  if S[i]!="U" and T[i]=="D":
    U[i] = max(U[i]-1, -1)
  if S[i]=="D" and (T[i]!="U" or D[i]>=H):
    D[i] -= 1
  if S[i]!="D" and T[i]=="U":
    D[i] = min(D[i]+1, H)
  if L[i]+1>=R[i] or U[i]+1>=D[i]:
    ans = "NO"

if sr<=U[0] or D[0]<=sr or sc<=L[0] or R[0]<=sc:
  ans = "NO"
print ans
