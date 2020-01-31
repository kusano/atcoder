N = input()
A = [0]*N
B = [0]*N
for i in range(N):
  A[i], B[i] = map(int, raw_input().split())

AB = zip(B, A)
AB.sort()
x = 10**9
for b, a in AB[::-1]:
  x = min(x, b)-a
print "Yes" if x>=0 else "No"
