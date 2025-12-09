#!/bin/python3

"""
Check that there are not repeats in hours, elves, reindeer_id's.
To test manually: 
    python3 ./input_validators/reindeersandelves.py < ./data/sample/1.in
    echo $?
"""

import sys

def validation():
    lines = sys.stdin.read().strip().split('\n')
    if len(lines) < 2:
        return False
    parts = lines[0].split()
    r, e, g = map(int, parts)
    # l = 0 are the first 3 integers and are checked by the ctd file
    l = 1 
    
    prev_reindeer = set()
    for reindeer_id in range(1, r+1):
        try:
            id = int(lines[l])
            l += 1
        except Exception as e:
            return False
        assert 1 <= id <= r
        assert id not in prev_reindeer
        prev_reindeer.add(id)

        prev_hours = set()

        while True:
            try:
                parts = lines[l].split()
                l += 1
            except IndexError:
                return False
            assert len(parts) >= 1
            hour = int(parts[0])
            if hour == 0:
                break
            assert 1 <= hour <= 24
            assert hour not in prev_hours
            prev_hours.add(hour)
            assert len(parts) >= 2

            elves = [int(x) for x in parts[1:]]
            for elf in elves:
                assert 1 <= elf <= e
            assert len(elves) == len(set(elves))
    assert len(prev_reindeer) == r
    assert prev_reindeer == set(range(1, r+1))
    assert l == len(lines)
    return True

def main():
    try: 
        if validation():
            sys.exit(42)
        else:
            sys.exit(43)
    except Exception as e:
        sys.exit(43)
    
if __name__ == "__main__":
    main()