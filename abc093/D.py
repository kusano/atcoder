# max(1*(a+n-1), 2*(a+n-2), ..., n*a)
def f(a, n):
  x = min((a+n)/2, n)
  y = a+n-x
  return x*y

Q = input()
for _ in range(Q):
  A, B = map(int, raw_input().split())
  if A>B:
    A,B = B,A
  n = 0
  b = 2**32
  while b>0:
    if f(A+1, n+b)<A*B:
      n += b
    b /= 2
  print A-1+n
