// https://leetcode.com/problems/watering-plants-ii/

package minimumRefill

object Solution {
  def minimumRefill(plants: Array[Int], capacityA: Int, capacityB: Int): Int = {
    val n = plants.size
    val mid = (n - 1) / 2
    val isOdd = (n & 1) == 1
    var count = 0
    var cA = capacityA
    var cB = capacityB

    (0 to mid) foreach { i =>
      isOdd && i == mid match {
        case false =>
          cA < plants(i) match {
            case true =>
              cA = capacityA
              count += 1
              println("A cap filled to ", cA)
            case _ =>
          }
          // println(s"cA - plants($i) = $cA - ${plants(i)} = ${cA - plants(i)}")
          cA -= plants(i)
        case _ =>
      }
    }
    (n - 1 to mid + 1 by -1) foreach { i =>
      cB < plants(i) match {
        case true =>
          cB = capacityB
          count += 1
          println("B cap filled to ", cB)
        case _ =>
      }
      // println(s"cB - plants($i) = $cB - ${plants(i)} = ${cB - plants(i)}")
      cB -= plants(i)
    }

    isOdd match {
      case true =>
        cB <= cA match {
          case true =>
            cA < plants(mid) match {
              case true =>
                count += 1
              case _ =>
            }
          case false =>
            cB < plants(mid) match {
              case true =>
                count += 1
              case _ =>
            }
        }
      case _ =>
    }

    count
  }
}
