N, K = map(int, raw_input().split())
l = map(int, raw_input().split())

print sum(sorted(l)[N-K:])
