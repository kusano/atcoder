s = raw_input()
k = input()

print len(set(s[i:i+k] for i in range(len(s)-k+1)))
