# min(xA+yC)
# const. H+xB+yD > (N-x-y)E

N, H = map(int, raw_input().split())
A, B, C, D, E = map(int, raw_input().split())

ans = N*A
for x in range(N+1):
  y = (N*E-x*E-H-x*B+E+D)/(E+D)
  if x+y<=N:
    ans = min(ans, x*A+max(y, 0)*C)
print ans
