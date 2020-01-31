R, C = map(int, raw_input().split())
X, Y = map(int, raw_input().split())
D, L = map(int, raw_input().split())

M = 10**9+7

def comb(A, B):
  if A<B:
    return 0
  r = 1
  for i in range(B):
    r *= A-i
    r %= M
  for i in range(B):
    r *= pow(i+1, M-2, M)
    r %= M
  return r

ans = (
  + comb(X*Y, D+L)              # (0,0), (-1,0)*2, (-2,0), (0,-1)*2, (0,-2), (-1,-1)*4, (-1,-2)*2, (-2,-1)*2, (-2,-2)
  - comb((X-1)*Y, D+L)*2        # (-1,0)*2, (-2,0)*2, (-1,-1)*4, (-1,-2)*2, (-2,-1)*4, (-2,-2)*2
  + comb((X-2)*Y, D+L)          # (-2,0), (-2,-1)*2, (-2,-2)
  - comb(X*(Y-1), D+L)*2        # (0,-1)*2, (0,-2)*2, (-1,-1)*4, (-2,-1)*2, (-1,-2)*4, (-2,-2)*2
  + comb(X*(Y-2), D+L)          # (0,-2), (-1,-2)*2, (-2,-2)
  + comb((X-1)*(Y-1), D+L)*4    # (-1,-1)*4, (-1,-2)*4, (-2,-1)*4, (-2,-2)*4
  - comb((X-2)*(Y-1), D+L)*2    # (-2,-1)*2, (-2,-2)*2
  - comb((X-1)*(Y-2), D+L)*2    # (-1,-2)*2, (-2,-2)*2
  + comb((X-2)*(Y-2), D+L)      # (-2,-2)
)
if X==1 and Y==1:
  ans = 1
ans *= comb(D+L, D) * (R-X+1) * (C-Y+1)
print ans%M
