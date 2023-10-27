// https://leetcode.com/problems/smallest-value-of-the-rearranged-number/
package smallestNumber
import scala.collection.mutable

object Solution {
  def smallestNumber(num: Long): Long = {
    val s = mutable.ArrayBuffer[Int]()
    var res = 0L
    val base = 10L
    var mul = 1L
    extract(num.abs, s)
    s.sortInPlace()

    num < 0 match {
      case true =>
        s foreach { x =>
          res = mul * x + res
          mul *= base
        }
        res *= -1

      case _ =>
        var firstNonZero = true

        s foreach { x =>
          x match {
            case 0 => mul *= base
            case _ =>
              firstNonZero match {
                case true =>
                  res = x * mul
                  firstNonZero = false
                case _ =>
                  res = res * base + x
              }
          }
        }
    }

    res
  }

  def extract(num: Long, s: mutable.ArrayBuffer[Int]): Unit = {
    num match {
      case 0 =>
      case _ =>
        s.append((num % 10).toInt)
        extract(num / 10, s)
    }
  }
}
