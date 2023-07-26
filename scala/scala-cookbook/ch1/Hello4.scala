object something:
  def main(args: Array[String]): Unit =
    val out = args.map(_.length)
    println(s"2 main inside object: ${out}")
// scalac Hello4.scala
// scala something
