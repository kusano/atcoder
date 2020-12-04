S, P = map(int, input().split())

ans = "No"
N = 1
while N*N<=P:
  if P%N==0:
    M = P//N
    if N+M==S:
      ans = "Yes"
      break
  N += 1
print(ans)
