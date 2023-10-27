// https://leetcode.com/problems/k-radius-subarray-averages/
package getAverages

object Solution {
  def getAverages(nums: Array[Int], k: Int): Array[Int] = {
    val n = nums.size
    if ((n - 1) / 2 < k) {
      nums.mapInPlace(_ => -1)
      return nums
    }
    val w = 2 * k + 1
    val res = Array.fill(n - w + 1) { -1 }
    var s: Long = 0
    (0 to w - 1) foreach { i =>
      s += nums(i)
    }
    var j = 0
    res(j) = (s / w).toInt
    j += 1

    (k + 1 to n - 1 - k) foreach { i =>
      s -= nums(i - k - 1)
      s += nums(i + k)
      res(j) = (s / w).toInt
      j += 1
    }

    j = 0

    (0 to n - 1) foreach { i =>
      k <= i && i <= n - 1 - k match {
        case true =>
          nums(i) = res(j)
          j += 1
        case false =>
          nums(i) = -1
      }
    }

    nums
  }
}
