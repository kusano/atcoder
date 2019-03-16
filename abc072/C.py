N = input()
a = map(int, raw_input().split())

T = [0]*100000
for x in a:
  T[x] += 1
ans = 0
for i in range(99998):
  ans = max(ans, sum(T[i:i+3]))
print ans
