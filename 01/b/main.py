import sys

x, y = [], []

with open(sys.argv[1]) as f:
    for line in f:
        x_str, y_str = line.strip().split()
        x.append(int(x_str))
        y.append(int(y_str))

print(sum(xx * y.count(xx) for xx in x))
