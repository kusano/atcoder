from fractions import gcd

A, B, C, D = map(int, raw_input().split())

def f(X):
  return X-X/C-X/D+X/(C*D/gcd(C,D))
print f(B)-f(A-1)
