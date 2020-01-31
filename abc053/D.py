N = input()
A = map(int, raw_input().split())

ans = len(set(A))
if ans%2==0:
  ans -= 1
print ans
