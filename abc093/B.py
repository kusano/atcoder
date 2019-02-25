A, B, K = map(int, raw_input().split())

for a in sorted(list(set(range(A,min(B+1,A+K))+range(max(A,B-K+1),B+1)))):
  print a
