import sys

lines = [line.rstrip('\n') for line in sys.stdin]

max_len = max(len(line) for line in lines)

score = 0
for line in lines[:-1]:
    p = pow(max_len - len(line), 2)
    score += p

print(score)
