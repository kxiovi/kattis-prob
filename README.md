I am open to the idea of having this problem appear in a future contest `vvidhiiipatel@gmail.com`.

# General
Author: Vidhi Patel  
ID: 1702707

# Algorithm Description
Algorithm: The solution implements network flow using kactl's Dinic implementation. Since the solution utilizes a unit network (where each edge has a capacity of 1), the time complexity is O(sqrt(V) * E). 

The solution uses Dinic's algorithm to create a network flow. The network has this structure: 
`source --> reindeer-hour nodes --> elf-hour nodes --> sink`. This structure ensures that each available reindeer
pairs with only 1 elf in a hour, and that each elf is only paired once in an hour. The source node is index 0, 
the reindeer-hour nodes, of which there are *r* * 24, are indexes 1 to *r* * 24. Then, the elf-hour nodes, of which there
are *e* * 24, are indexes *r* * 24 to *r* * 24 + *e* * 24. The sink is index *r* * 24 + *e* * 24 + 1.  

> Note: number of reindeer = *r* and number of elves = *e*

# Test Cases Description
The sample test cases are simple, to help develop intuition for the problem. 
The secret tests cases:  
```
    01: number of max gifts possible is 5400. so if gift count is above that, it's impossible  

    02: overflows if the solution doesn't use a 64-bit integer for storing gift count *g*  

    03: stress case, max of all inputs. This wouldn't be too stressful if code accounts for 5400 gifts possible  

    04: tests the minimum of all inputs  
    
    05: tests the max of all inputs except *g* is 5400 in the case that solution has a trick to exit at a certain threshold of *g*  

    06: random, just so it may somehow catch something missed by other test cases  

    07: a test that should output `possible` because most of these tests either output 
    `impossible` or are very simple  
```
> Note: The reason that the maximum gifts *g* that would allow output to be `possible` is 5400
is because there are only up to 9 reindeer, working for 24 hours. If all 9 reindeer
are paired with elf for all 24 hours, the gifts ouputted would be: `9 * 24 * 25 =  5400`.
