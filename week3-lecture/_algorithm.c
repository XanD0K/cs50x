/*
Running Time

(O(n)) → Big O of ...
The ammount of steps might it take to run
It considers the worst case scenario (upper bounds)
Used to analyze how good/bad the algorithm is
Some commom running times:
- O(n²)         → Selection Sort // Bubble Sort
- O(n log n)    → Merge Sort
- O(n)          → Linear Search
- O(log n)      → Binary Search (better for sorted arrays)
- O(1)


Ω (Omega)
It considers the best cas scenario (lower bounds)
- Ω(n²)         → Selection Sort
- Ω(n log n)    → Merge Sort
- Ω(n)          → Bubble Sort
- Ω(log n)
- Ω(1)          → Linear Search // Binary Search


Θ (Theta)
Used when O and Ω happen to be the same
- Θ(n²)         → Selection Sort
- Θ(n log n)    → Merge Sort
- Θ(n)
- Θ(log n)
- Θ(1)



Sorting
Selection Sort
On each iteration, the algorithm selects the smallest element

Bubble Sort
Get the biggest elements to "bubble" their way up to the end of the list, one at a time


Recursion
A function that's defined in terms of itself, a function that calls itself
It uses 'base cases', which are conditionals that ask a question to which the answer is going to be YES or NO


Merge Sort
Uses recursion to get half of the problem and sort it
After sort is completed, it mergers the sorted halves

if only one number
    quit
else
    sort left half of numbers
    sort right half of numbers
    merge sorted halves
*/