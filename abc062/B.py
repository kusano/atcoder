H, W = map(int, raw_input().split())
a = [raw_input() for _ in range(H)]

print "#"*(W+2)
for t in a:
  print "#"+t+"#"
print "#"*(W+2)
