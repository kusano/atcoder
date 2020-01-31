N = input()
S = [raw_input() for _ in range(2)]

T = [[[0]*3 for i in range(3)] for j in range(N)]

for i in range(3):
  for j in range(3):
    if S[0][0]==S[1][0] and i==j or S[0][0]!=S[1][0] and i!=j:
      T[0][i][j] += 1

for i in range(1, N):
  for p0 in range(3):
    for p1 in range(3):
      for c0 in range(3):
        for c1 in range(3):
          if ((S[0][i-1]==S[0][i] and p0==c0 or S[0][i-1]!=S[0][i] and p0!=c0) and
              (S[1][i-1]==S[1][i] and p1==c1 or S[1][i-1]!=S[1][i] and p1!=c1) and
              (S[0][i]==S[1][i] and c0==c1 or S[0][i]!=S[1][i] and c0!=c1)):
            T[i][c0][c1] += T[i-1][p0][p1]
            T[i][c0][c1] %= 1000000007
ans = 0
for i in range(3):
  for j in range(3):
    ans += T[-1][i][j]
    ans %= 1000000007
print ans
