// resources:   inclusion-exclusion principle: https://codeforces.com/blog/entry/64625

# import cProfile

"""
logic: one line of the grid (at least) must be 'x'
the possible lines 
 - row x n
 - col x n
 - diag x 2
 - anti-diag x 2
Thus there are n + n + 4 sets.
"""
def count_X_lines(n, grid):
    # empty = [(r, c) for r in range(n) for c in range(n) if grid[r][c] == '.']
    empty = {(r, c) for r in range(n) for c in range(n) if grid[r][c] == '.'}
    k = len(empty)

    lines = []

    # all possible lines that don't have 'o' added to lines
    # b/c those lines will never be a full line of 'x'
    for i in range(n):
        row = [(i, c) for c in range(n)]
        col = [(r, i) for r in range(n)]
        if all(grid[r][c] != 'O' for r, c in row):
            lines.append(row)
        if all(grid[r][c] != 'O' for r, c in col):
            lines.append(col)
    diag = [(i, i) for i in range(n)]
    antidiag = [(i, n-1-i) for i in range(n)]
    if all(grid[r][c] != 'O' for r, c in diag):
        lines.append(diag)
    if all(grid[r][c] != 'O' for r, c in antidiag):
        lines.append(antidiag)

    # inclusion–exclusion 
    ans = 0
    m = len(lines)
    set_lines = [set(line) for line in lines]
    for s in range(1, 1 << m):
        setx = set() # will contain cells from empty that are set to x to create line
        for i in range(m):
            if s & (1 << i):  # isolate lines in curr subset
                setx = setx | set_lines[i] & empty
        e = -1 if bin(s).count('1') % 2 == 0 else 1  # -1 if even, 1 if odd
        ans += e * (1 << (k - len(setx)))
    return ans

def main():
    n = int(input())
    grid = []
    for _ in range(n):
        grid.append(input())
    
    tot = count_X_lines(n, grid)
    print(tot)


    
    # if full = 1




if __name__ == "__main__":
    # cProfile.run('main()')
    main()