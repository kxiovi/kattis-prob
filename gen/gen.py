#!/opt/local/bin/python
"""
test case generator
usage: python3 gen.py 

constraints: 
    r: [1, 9]
    e: [1, 25000]
    g: [1, 18446744073709551615] but practically g: [1, 5400]
"""

import sys
import random
import os

random.seed(10101)

MAXR = 9
MAXE = 25000
MAXG = 18446744073709551615

def gen(file, data):
    path = os.path.join("data", "secret", file)
    with open(path, 'w') as f:
        f.write(data)
    

def case_1():
    '''
    # max gifts possible is 5400. so if gift count is above that, impossible
    '''

    r = random.randint(1, MAXR)
    e = random.randint(1, MAXE)
    g = random.randint(5401, MAXG)

    data = [f"{r} {e} {g}"]
    for reindeer in range(1, r+1):
        data.append(str(reindeer))
        num_hours = random.randint(1, 24)
        hours = sorted(random.sample(range(1, 25), num_hours))
        for h in hours: 
            num_elves = random.randint(1, e)
            elves = sorted(random.sample(range(1, e+1), num_elves))
            data.append(f"{h} " + " ".join(map(str, elves)))
        data.append("0")
    return "\n".join(data) + "\n"

def case_2(): 
    '''
    overflow if solution doesn't use 64 bit for storing gift count
    '''

    r = random.randint(1, MAXR)
    e = random.randint(1, MAXE)
    g = MAXG 
    data = [f"{r} {e} {g}"]
    for reindeer in range(1, r+1):
        data.append(str(reindeer))
        num_hours = random.randint(1, 24)
        hours = sorted(random.sample(range(1, 25), num_hours))
        for h in hours: 
            num_elves = random.randint(1, e)
            elves = sorted(random.sample(range(1, e+1), num_elves))
            data.append(f"{h} " + " ".join(map(str, elves)))
        data.append("0")
    return "\n".join(data) + "\n"


def case_3():
    '''
    stress case: max of all inputs
    '''

    r = MAXR
    e = MAXE
    g = MAXG 
    data = [f"{r} {e} {g}"]
    for reindeer in range(1, r+1):
        data.append(str(reindeer))
        num_hours = 24
        hours = sorted(random.sample(range(1, 25), num_hours))
        for h in hours: 
            num_elves = 25000
            elves = sorted(random.sample(range(1, e+1), num_elves))
            data.append(f"{h} " + " ".join(map(str, elves)))
        data.append("0")
    return "\n".join(data) + "\n"

def case_4():
    '''
    test minimo of all values
    '''

    r = 1
    e = 1
    g = 1 
    data = [f"{r} {e} {g}"]
    for reindeer in range(1, r+1):
        data.append(str(reindeer))
        num_hours = random.randint(1, 24)
        hours = sorted(random.sample(range(1, 25), num_hours))
        for h in hours: 
            num_elves = random.randint(1, e)
            elves = sorted(random.sample(range(1, e+1), num_elves))
            data.append(f"{h} " + " ".join(map(str, elves)))
        data.append("0")
    return "\n".join(data) + "\n"


def case_5():
    '''
    max of all inputs except g is 5400 in the case that solution has a trick 
    to exit at a certain threshold of g
    '''

    r = MAXR
    e = MAXE
    g = 5400
    data = [f"{r} {e} {g}"]
    for reindeer in range(1, r+1):
        data.append(str(reindeer))
        num_hours = random.randint(1, 24)
        hours = sorted(random.sample(range(1, 25), num_hours))
        for h in hours: 
            num_elves = random.randint(1, e)
            elves = sorted(random.sample(range(1, e+1), num_elves))
            data.append(f"{h} " + " ".join(map(str, elves)))
        data.append("0")
    return "\n".join(data) + "\n"

    
def case_6(): 
    '''
    random
    '''

    r = random.randint(1, MAXR)
    e = random.randint(1, MAXE)
    g = random.randint(1, 5400)

    data = [f"{r} {e} {g}"]
    for reindeer in range(1, r+1):
        data.append(str(reindeer))
        num_hours = random.randint(1, 24)
        hours = sorted(random.sample(range(1, 25), num_hours))
        for h in hours: 
            num_elves = random.randint(1, e)
            elves = sorted(random.sample(range(1, e+1), num_elves))
            data.append(f"{h} " + " ".join(map(str, elves)))
        data.append("0")
    return "\n".join(data) + "\n"

def case_7():
    '''
    simple, possible
    '''

    r = 3
    e = 10
    g = 150
    num_hours = 2

    data = [f"{r} {e} {g}"]
    for reindeer in range(1, r+1):
        data.append(str(reindeer))
        num_hours = random.randint(1, 24)
        hours = sorted(random.sample(range(1, 25), num_hours))
        for h in hours: 
            num_elves = random.randint(1, e)
            elves = sorted(random.sample(range(1, e+1), num_elves))
            data.append(f"{h} " + " ".join(map(str, elves)))
        data.append("0")
    return "\n".join(data) + "\n"


def case_8():
    '''
    Another case that is possible because that are very many elves in comparison to deer
    As well, deer work all hours
    '''

    r = 9
    e = 4000
    g = 3500

    data = [f"{r} {e} {g}"]
    for reindeer in range(1, r+1):
        data.append(str(reindeer))
        num_hours = random.randint(1, 24)
        # hours = sorted(random.sample(range(1, 25), num_hours))
        for h in range(1, 25): 
            num_elves = random.randint(20, e)
            elves = sorted(random.sample(range(1, e+1), num_elves))
            data.append(f"{h} " + " ".join(map(str, elves)))
        data.append("0")
    return "\n".join(data) + "\n"
    

def main():
    tests = [
        ("01.in", case_1), 
        ("02.in", case_2), 
        ("03.in", case_3), 
        ("04.in", case_4), 
        ("05.in", case_5), 
        ("06.in", case_6), 
        ("07.in", case_7), 
        ("08.in", case_8)
    ]

    tests = [
        ("08.in", case_8)
    ]

    for file, g in tests:
        data = g()
        gen(file, data)
    

if __name__ == "__main__":
    main()