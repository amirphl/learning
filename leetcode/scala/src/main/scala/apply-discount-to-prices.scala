// https://leetcode.com/problems/apply-discount-to-prices/
package discountPrices

object Solution {
  def discountPrices(sentence: String, discount: Int): String = {
    sentence
      .split(' ')
      .mapInPlace { s =>
        s.startsWith("$") match {
          case true =>
            val suffix = s.substring(1)

            suffix forall Character.isDigit match {
              case true =>
                suffix.toDoubleOption match {
                  case Some(x) =>
                    val y = (x * (100 - discount)) / 100
                    "$" + f"$y%.2f"
                  case None => s
                }
              case _ => s
            }
          case _ => s
        }
      }
      .reduce(_ + " " + _)
  }
}
