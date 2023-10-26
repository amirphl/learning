// https://leetcode.com/problems/all-divisions-with-the-highest-score-of-a-binary-array/
package maxScoreIndices
import scala.collection.mutable

object Solution {
  def maxScoreIndices(nums: Array[Int]): List[Int] = {
    var zeros = 0
    var ones = nums.sum
    var score = ones
    val res = mutable.ListBuffer[Int]()
    res.append(0)

    (0 to nums.size - 1).foreach { i =>
      val x = nums(i)

      x match {
        case 0 =>
          zeros += 1
        case _ =>
          ones -= 1
      }

      zeros + ones match {
        case v if v == score =>
          res += i
        case v if v > score =>
          score = v
          res.clear()
          res += i
        case _ =>
      }
    }
    res.toList
  }
}
