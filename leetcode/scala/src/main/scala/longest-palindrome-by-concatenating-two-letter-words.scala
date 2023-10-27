// https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/
package longestPalindrome

object Solution {
  def longestPalindrome(words: Array[String]): Int = {
    val arr = Array.ofDim[Int](26, 26)
    var count = 0
    words foreach { w =>
      val row = w(0) - 'a'
      val col = w(1) - 'a'
      arr(col)(row) == 0 match {
        case true =>
          arr(row)(col) += 1
        case _ =>
          arr(col)(row) -= 1
          count += 1
      }
    }

    var sym = 0
    (0 to 25) foreach { i =>
      sym += arr(i)(i)
    }

    val mid = sym match {
      case 0 => 0
      case _ => 2
    }

    count * 4 + mid
  }
}
