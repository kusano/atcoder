N = input()
print sum(sorted(map(int, raw_input().split()))[N::2])
