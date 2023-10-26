// https://leetcode.com/problems/average-waiting-time/

object Solution {
  def averageWaitingTime(customers: Array[Array[Int]]): Double = {
    var curr = customers(0)(0)
    var total: Double = 0

    customers.foreach { x =>
      curr <= x(0) match {
        case true =>
          curr = x(0)
        case _ =>
      }

      total += curr - x(0) + x(1)
      curr += x(1)
    }

    total / customers.length
  }

  def main(args: Array[String]): Unit = {
    val customers = Array.ofDim[Int](3, 2)
    customers(0) = Array(1, 2)
    customers(1) = Array(3, 5)
    customers(2) = Array(4, 6)
    println(averageWaitingTime(customers))
  }
}
