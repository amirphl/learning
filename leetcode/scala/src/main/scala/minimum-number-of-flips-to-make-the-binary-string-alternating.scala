package MinFlips
// https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/

object Solution {
  def minFlips(s: String): Int = {
    val n = s.size
    val oddIndex = ((n - 1) & 1) == 1
    var ans = Int.MaxValue
    var ans1 = 0
    var ans2 = 0

    (0 to n - 1).foreach { i =>
      val oddIndex = (i & 1) == 1

      s(i) == '0' match {
        case true if oddIndex   => ans1 += 1
        case true if !oddIndex  => ans2 += 1
        case false if !oddIndex => ans1 += 1
        case false if oddIndex  => ans2 += 1
        case _                  =>
      }

      ans = math.min(ans1, ans2)
    }

    (1 to n - 1).foreach { i =>
      s(i - 1) == '0' match {
        case true  => ans2 -= 1
        case false => ans1 -= 1
      }

      val temp = ans1
      ans1 = ans2
      ans2 = temp

      s(i - 1) == '0' match {
        case true if oddIndex   => ans1 += 1
        case true if !oddIndex  => ans2 += 1
        case false if !oddIndex => ans1 += 1
        case false if oddIndex  => ans2 += 1
        case _                  =>
      }

      ans = math.min(ans, math.min(ans1, ans2))
    }

    ans
  }
}
