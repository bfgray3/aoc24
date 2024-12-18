import sys

x, y = [], []

with open(sys.argv[1]) as f:
    for line in f:
        x_str, y_str = line.strip().split()
        x.append(int(x_str))
        y.append(int(y_str))

x.sort()
y.sort()

print(sum(abs(xx - yy) for xx, yy in zip(x, y)))
