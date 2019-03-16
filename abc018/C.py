R, C, K = map(int, raw_input().split())
s = [raw_input() for _ in range(R)]

T = [[0]*(R+C-1) for _ in range(R+C-1)]

for y in range(R+C-1):
  for x in range(R+C-1):
    if (x+y)%2!=R%2:
      T[y][x] = 1
for y in range(R):
  for x in range(C):
    if s[y][x]=="o":
      T[x+y][R+x-y-1] = 0

S = [[0]*(R+C-1) for _ in range(R+C-1)]
for y in range(R+C-1):
  for x in range(R+C-1):
    S[y][x] = (
      + T[y][x]
      + (S[y][x-1] if x>0 else 0)
      + (S[y-1][x] if y>0 else 0)
      - (S[y-1][x-1] if x>0 and y>0 else 0))

ans = 0
for y in range(2*K-2, R+C-1):
  for x in range(2*K-2, R+C-1):
    if (x+y)%2!=R%2:
      s = (
        + S[y][x]
        - (S[y-(2*K-1)][x] if y-(2*K-1)>=0 else 0)
        - (S[y][x-(2*K-1)] if x-(2*K-1)>=0 else 0)
        + (S[y-(2*K-1)][x-(2*K-1)] if y-(2*K-1)>=0 and x-(2*K-1)>=0 else 0))
      if s==0:
        ans += 1
print ans
