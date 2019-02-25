N, X = map(int, raw_input().split())
m = [input() for _ in range(N)]

print N + (X-sum(m))/min(m)
