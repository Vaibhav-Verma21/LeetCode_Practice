

from collections import defaultdict

class Solution:
    def canPartitionGrid(self, grid: List[List[int]]) -> bool:

        def check_1d(arr):
            l, r = 0, sum(arr)
            for i in range(len(arr)-1):
                v = arr[i]
                l += v
                r -= v
                if l == r:
                    return True
                if i > 0 and (l - arr[0] == r or l-arr[i] == r):
                    return True
            return False


        def check(grid, sm):
            seen = set()
            top_sm = 0
            bot_sm = sm

            for i in range(len(grid)-1):
                row_sm = sum(grid[i])
                top_sm += row_sm
                bot_sm -= row_sm
                seen.update(grid[i])
                if top_sm == bot_sm:
                    return True
                if top_sm > bot_sm:
                    diff = top_sm - bot_sm
                    if diff in seen:
                        if i >= 1:
                            return True
                        elif grid[0][0] == diff or grid[0][-1] == diff:
                            return True
                    else:
                        break

            return False
            
        m, n = len(grid), len(grid[0])
        if m == 1 and n == 1:
            return False
        if m == 1:
            return check_1d(grid[0]) or check_1d(grid[0][::-1])
        if n == 1:
            transposed = list(zip(*grid))[0]
            return check_1d(transposed) or check_1d(transposed[::-1])
        
        transposed = list(zip(*grid))
        sm = sum(sum(row) for row in grid)
        return \
            check(grid, sm) or \
            check(grid[::-1], sm) or \
            check(transposed, sm) or \
            check(transposed[::-1], sm)