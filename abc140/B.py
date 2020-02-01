N = input()
A = [int(t)-1 for t in raw_input().split()]
B = map(int, raw_input().split())
C = map(int, raw_input().split())

ans = 0
for i in range(N):
  ans += B[A[i]]
  if i>0 and A[i]==A[i-1]+1:
    ans += C[A[i-1]]
print ans
