// Copyright 2019 Qi Wang
// Date: 2019-03-16
// Method 2. Refers to other's solution
object Solution {
  def largestSumAfterKNegations(A: Array[Int], K: Int): Int = {
    val negs = A.filter(_ < 0)
    val positives = A.filter(_ > 0)
    val min_abs = A.map(v => Math.abs(v)).min
    if (K > negs.length) {
      val sub = if ((K - negs.length) % 2 == 0) 0 else min_abs
      (-negs.sum + positives.sum) - 2 * sub
    } else {
      negs
        .sorted
        .zipWithIndex
        .map(v => if (v._2 < K) -v._1 else v._1)
        .sum + positives.sum
    }
  }
}

// Date: 2019-03-16
object Solution {
  def largestSumAfterKNegations(A: Array[Int], K: Int): Int = {
    val len = A.length
    var k = K
    if (K > len) {
      k = if ((K - len) % 2 == 0)  len else len - 1
    }
    return largestSumAfterKNegationsCore(A.sorted, k)
  }

  def largestSumAfterKNegationsCore(nums: Array[Int], k: Int): Int = k match {
    case 0 => nums.sum
    case _ =>
      println(nums.head)
      if (nums.head >= 0) {
        if (k % 2 == 0) nums.head else -nums.head + nums.tail.sum
      } else if (nums.tail.isEmpty) {
        -nums.head
      } else if (nums.tail.head <= 0 || (k % 2 == 1) || -nums.head > nums.tail.head) {
        -nums.head + largestSumAfterKNegationsCore(nums.tail, k - 1)
      } else {
        nums.sum
      }
  }
}