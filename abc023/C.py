R, C, K = map(int, raw_input().split())
N = input()
r = [0]*N
c = [0]*N
for i in range(N):
  r[i], c[i] = map(int, raw_input().split())
  r[i] -= 1
  c[i] -= 1

RN = [0]*R
CN = [0]*C
for i in range(N):
  RN[r[i]] += 1
  CN[c[i]] += 1

RT = [0]*(N+1)
for rn in RN:
  RT[rn] += 1

ans = 0
for cn in CN:
  if K-cn>=0:
    ans += RT[K-cn]

for i in range(N):
  t = RN[r[i]] + CN[c[i]]
  if t==K+1:
    ans += 1
  if t==K:
    ans -= 1

print ans
