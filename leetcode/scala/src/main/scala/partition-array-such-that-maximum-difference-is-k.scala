// https://leetcode.com/problems/partition-array-such-that-maximum-difference-is-k/
package partitionArray

object Solution {
  def partitionArray(nums: Array[Int], k: Int): Int = {
    nums.sortInPlace()
    var count = 1
    var prev = nums(0)

    nums foreach { elem =>
      k < elem - prev match {
        case true =>
          count += 1
          prev = elem
        case _ =>
      }
    }

    count
  }
}
