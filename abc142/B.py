N, K = map(int, raw_input().split())
h = map(int, raw_input().split())

print sum(x>=K for x in h)
