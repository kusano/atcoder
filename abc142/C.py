N = input()
A = map(int, raw_input().split())

ans = [0]*N
for i in range(N):
  ans[A[i]-1] = i+1

print " ".join(map(str, ans))
