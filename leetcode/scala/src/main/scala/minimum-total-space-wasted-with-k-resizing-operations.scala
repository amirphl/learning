// https://leetcode.com/problems/minimum-total-space-wasted-with-k-resizing-operations/
package minSpaceWastedKResizing
import scala.collection.mutable

// This solution doesn't work for testcase [20, 10]
object Solution {
  def minSpaceWastedKResizing(nums: Array[Int], k: Int): Int = {
    val pq = mutable.PriorityQueue[(Int, Int)]()(Ordering.by(_._1))
    nums.indices.foreach { i => pq.enqueue((nums(i), i)) }
    val t = kth(pq, k, (Int.MaxValue, nums.size))
    var w = t.getOrElse((Int.MaxValue, nums.size))._1
    var sum = 0
    nums.foreach { e =>
      e > w match {
        case true  => w = e
        case false => sum += w - e
      }
    }
    sum
  }

  def kth(
      pq: mutable.PriorityQueue[(Int, Int)],
      k: Int,
      prev: (Int, Int)
  ): Option[(Int, Int)] = {
    pq.nonEmpty match {
      case true =>
        val top = pq.dequeue()

        (prev._2 < top._2 || prev._1 == top._1) match {
          case true => kth(pq, k, prev)
          case _ =>
            k match {
              case 0 => Some(top)
              case _ => kth(pq, k - 1, top)
            }
        }
      case _ => Some(prev)
    }
  }
}
