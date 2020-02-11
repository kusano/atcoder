N = input()
m = map(int, raw_input().split())

print sum(max(0, 80-x) for x in m)
