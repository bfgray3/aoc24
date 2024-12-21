import sys
from collections.abc import Iterable
from itertools import pairwise


def is_safe(x: Iterable[int]) -> bool:
    for i, (a, b) in enumerate(pairwise(x)):
        diff = a - b
        if not i:
            is_negative = diff < 0
        else:
            if (diff < 0) is not is_negative:
                return False
        if not 1 <= abs(diff) <= 3:
            return False
    return True


with open(sys.argv[1]) as f:
    reports = [[int(ln) for ln in line.strip().split()] for line in f]

print(sum(is_safe(r) for r in reports))
