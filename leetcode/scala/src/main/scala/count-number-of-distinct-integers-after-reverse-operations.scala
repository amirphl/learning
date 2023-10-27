// https://leetcode.com/problems/count-number-of-distinct-integers-after-reverse-operations/
package countDistinctIntegers
import scala.collection.mutable

object Solution {
  def countDistinctIntegers(nums: Array[Int]): Int = {
    val s = mutable.HashSet.from(nums)

    nums.foreach { x =>
      s add x.toString.reverse.toInt
    }

    s.size
  }
}
