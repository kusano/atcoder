N, A, B, C, D = map(int, raw_input().split())

for m in range(N):
  if A-m*D+(N-m-1)*C <= B <= A-m*C+(N-m-1)*D:
    print "YES"
    exit(0)
print "NO"
