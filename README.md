# Sort
  - bubble sort

<br>

# Array

## Sum
  - LC 209. Minimum Size Subarray Sum
  - LC 523. Continuous Subarray Sum (hash)
  - LC 525. Contiguous Array (hash)
  - LC 548. Split Array with Equal Sum (hash)

## Duplicate
  - LC 442. Find All Duplicates in an Array
  - LC 448. Find All Numbers Disappeared in an Array
  - Offer 51. duplicate

## Matrix
  - LC 363. Max Sum of Rectangle No Larger Than K (Google)
  - Hiho 1502. 最大子矩阵

## Other

  - LC 215. Kth Largest Element in an Array (same as Offer  30. GetLeastNumbers)

<br>

# String

## KMP
  - LeetCode 27. Implement strStr().
  - hihoCoder 1015. 

## Longest Palindromic Substring (prefix tree OR manacher)
  - LeetCode 5. Longest Palindromic Substring
  - hihoCode 1032.

<br>

# Graph

  - LC 200, 289, 317 share the similar counting technique, reducing the memory we used

## Topology
  
  - LC 310. Minimum Height Trees

## BFS

  - LC 286. Walls and Gates
  - LC 317. Shortest Distance from All Buildings

## Shortest path

### Dijkstra

  - LC 505. The Maze II


<br>

# Tree

## Traversal

  - Morris Traversal
    - LC 94. Binary Tree Inorder Traversal
    - LC 99. Recover Binary Search Tree
  - LC 549. Binary Tree Longest Consecutive Sequence II

<br>

# Permutation

  - LC 31. Next Permutation
  - LC 47. Permutations II
  - LC 267. Palindrome Permutations
  - LC 321. Create Maximum Number
  - LC 402. Remove K Digits
    - 321 and 402 are similar

<br>

# Bit Manipulation

  - LC 411. Minimum Unique Word Abbreviation
    - Bit Manipulation && Backtracking

<br>

# Iterator

  - LC 251. Flatten 2D Vector

<br>

# DP
  
  - LC 474. Ones and Zeroes

<br>

# Greedy

  - LC 316. Remove Duplicate Letters
  - LC 452. Minimum Number of Arrows to Burst Balloons, POJ 3069. Saruman's Army

<br>

# Hash

  - LC 159. Longest Substring with At Most Two Distinct Characters
  - LC 340. Longest Substring with At Most K Distinct Characters
  - LC 523. Continuous Subarray Sum
  - LC 525. Contiguous Array

<br>

# Binary Indexed Tree / Segment Tree

  - LC 308. Range Sum Query 2D - Mutable
  - https://www.topcoder.com/community/data-science/data-science-tutorials/binary-indexed-trees/

<br>

# Union Set

  - LC 305. Number of Islands II
    - Take care of the boundary test
      - Test whether a vector is empty before calling front() or back()
      - Test whether you are doing invalid index accessing -- grid[x][y], 0 <= x < m, 0 <= y < n

<br>

# STL

  - LC 538. Convert BST to Greater Tree
    - upper_bound(first, last, val): return last if no such element
    - distance(first, last) : first comes first