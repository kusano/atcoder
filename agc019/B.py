A = raw_input()

C = [0]*26
for a in A:
  C[ord(a)-ord("a")] += 1
ans = len(A)*(len(A)+1)/2+1
for c in C:
  ans -= c*(c+1)/2
print ans
