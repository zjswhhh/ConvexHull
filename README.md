# ConvexHull
Implement convex hull algorithms.

INPUT FORMAT: The first line contains k, the number of problems. Then descriptions of the problems
follow. The first line contains n (the number of points). Then n lines follow each containing two integers
(the x and y coordinates); the coordinates have absolute value bounded by 10, 000.
OUTPUT FORMAT: The output contains one line for each problem—the indices of extreme points on the
convex hull listed in clock-wise order.

Solution 1: Javis's Algorithm O(n^2)
Solution 2: Graham’s Algorithm (Scanning) O(nlogn)

Reference: 
http://jeffe.cs.illinois.edu/teaching/373/notes/x05-convexhull.pdf
