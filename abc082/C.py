N = input()
a = map(int, raw_input().split())

ans = 0

T = [0]*(N+1)
for x in a:
  if x<=N:
    T[x] += 1
  else:
    ans += 1
for i in range(N+1):
  if T[i]>0:
    if T[i]>=i:
      ans += T[i]-i
    else:
      ans += T[i]
print ans
