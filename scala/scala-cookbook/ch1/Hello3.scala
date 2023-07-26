object something{
def main(args: Array[String]): Unit = {
  val out = args.map(_.length)
  println(s"main inside object: ${out}")
}
}
// scalac Hello3.scala
// scala something
