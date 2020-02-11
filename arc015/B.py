N = input()
C = [0]*6
for i in range(N):
  M, m = map(float, raw_input().split())
  if 35<=M:
    C[0] += 1
  if 30<=M<35:
    C[1] += 1
  if 25<=M<30:
    C[2] += 1
  if 25<=m:
    C[3] += 1
  if m<0 and 0<=M:
    C[4] += 1
  if M<0:
    C[5] += 1
print " ".join(map(str, C))
