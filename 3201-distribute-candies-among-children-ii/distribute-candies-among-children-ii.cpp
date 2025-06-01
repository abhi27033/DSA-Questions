class Solution {
public:
long long nck(long long n, long long k){
    if (k > n) return 0; 
    long long ans=1;
    for(int i=0;i<k;i++){
        ans*=(n-i);
        ans/=(i+1);
    }
    return ans;
}
    long long distributeCandies(int n, int limit) {
        long long a=nck(1LL*(n+2),2LL);
        long long b=nck(1LL*(n+2-(limit+1)),2LL);
        long long c=nck(1LL*(n+2-2*(limit+1)),2LL);
        long long d=nck(1LL*(n+2-3*(limit+1)),2LL);
        return a-3*b+3*c-d;
    }
};
/*
1. What (\U0001d45bC\U0001d458) means:
This is the number of ways to choose k items from n distinct items.
Order doesn’t matter.
Each item is used at most once.

This is used in problems like:
“From 10 students, choose 3 to go on a trip.”
This is not related to partitioning or distributing items.

2. What you're solving: Integer Partition (Combinatorics)
You're solving:
\U0001d4651+\U0001d4652+⋯+\U0001d465\U0001d458=\U0001d45b,\U0001d465\U0001d456≥0​
You want to know how many integer solutions exist to this equation — that is, how to partition \U0001d45b
candies among \U0001d458 buckets (people), allowing zero in some buckets.

This is a classic "stars and bars" problem, and the number of solutions is:
(\U0001d45b+\U0001d458−1 C \U0001d458−1)
Dividors are k-1
Suppose k=2(Partitions but dividor is 1, i.e, k-1)
Total positions now n+k-1
Select  k-1
so (n+k-1 C k-1)
_ _ _ _ _
_|_ _ _ _
_ _ _|_ _
This was Distribute n identical items to k bins (no upper bound)

Now we want Distribute n items to k bins, each ≤ m
Subtract the number of "bad" solutions
Let’s define:\U0001d434\U0001d456 : the set of solutions where person \U0001d456 gets more than m candies
We want to exclude all solutions in the union:
\U0001d434=\U0001d4341∪\U0001d4342∪⋯∪\U0001d434\U0001d458 ​
So, valid solutions = total − invalid:
Valid=∣\U0001d447(\U0001d45b,\U0001d458)|−∣\U0001d4341∪\U0001d4342U⋯∪\U0001d434\U0001d458∣
Using the inclusion-exclusion principle:
∣\U0001d4341∪⋯∪\U0001d434\U0001d458∣=∑\U0001d457=1....\U0001d458(−1)^(\U0001d457+1) ∑ 1≤\U0001d4561<⋯<\U0001d456\U0001d457≤\U0001d458 ∣\U0001d434\U0001d4561∩⋯∩\U0001d434\U0001d456\U0001d457∣ 
We must compute the size of each intersection ∣\U0001d434\U0001d4561∩⋯∩\U0001d434\U0001d456\U0001d457∣
Suppose \U0001d457 specific people (say, \U0001d4561,\U0001d4562,...,\U0001d456j) each receive at least \U0001d45a+1 candies.
Let’s define new variables:
\U0001d465\U0001d4561′=\U0001d465\U0001d4561−(\U0001d45a+1),(since they must take at least \U0001d45a+1)
Similarly for others in the subset. Each of these \U0001d457 variables is reduced by \U0001d45a+1,
so the total is reduced by \U0001d457(\U0001d45a+1)

Now the new equation becomes:
\U0001d4651′+\U0001d4652′+⋯+\U0001d465\U0001d458′=\U0001d45b−\U0001d457(\U0001d45a+1),with all, \U0001d465\U0001d456′≥0
So we’re back to a standard integer solution problem — but with a reduced total.
The number of such solutions is:
(\U0001d45b−\U0001d457(\U0001d45a+1)+\U0001d458−1 C \U0001d458−1)
But this is only valid if \U0001d45b−\U0001d457(\U0001d45a+1)≥0, otherwise it's zero.
There are (k C j) ways to choose j variables that exceed m.
So the total number of bad solutions with exactly j variables exceeding m is:
(\U0001d458C\U0001d457)(\U0001d45b−\U0001d457(\U0001d45a+1)+\U0001d458−1 C \U0001d458−1)
a. three kids with any number of candies= n+2 C 2​ 
b. one kid with more than limit number of candies= n+2−(limit+1) C 2
c. two kids with more than limit number of candies= n+2−2∗(limit+1)​ C 2
d. three kids with more than limit number of candies= n+2−3∗(limit+1) C 2​ 
From the principle above, we get ANS = 1∗a−3∗b+3∗c−d
a single
b pairs
c triplets
*/