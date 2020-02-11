L, R = map(int, raw_input().split())
l = map(int, raw_input().split())
r = map(int, raw_input().split())

print sum(min(l.count(x), r.count(x)) for x in range(10, 41))
