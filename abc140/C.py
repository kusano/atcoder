N = input()
B = map(int, raw_input().split())

ans = B[0]
for i in range(N-2):
  ans += min(B[i], B[i+1])
ans += B[-1]
print ans
