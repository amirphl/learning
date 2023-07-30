@main def main : Unit =
  val h = "Hello"
  println(s"$h")
  println(s"${h}")
  println(f"--'$h%s'--")
  println(f"--'$h%10s'--")
  println(f"--'$h%-10s'--")
  println(f"--'${h}%-10s'--")

  println("------------")

  var doubleNum = 105552323.2348762783
  println(f"$doubleNum%.1f")
  println(f"$doubleNum%.2f")
  println(f"$doubleNum%8.2f")
  println(f"$doubleNum%8.4f")
  println(f"$doubleNum%20.4f")
  println(f"$doubleNum%020.2f")
  println(f"$doubleNum%-20.2f--")

  doubleNum = -105552323.2348762783
  println(f"$doubleNum%.1f")
  println(f"$doubleNum%.2f")
  println(f"$doubleNum%8.2f")
  println(f"$doubleNum%8.4f")
  println(f"$doubleNum%20.4f")
  println(f"$doubleNum%020.2f")
  println(f"$doubleNum%-20.2f--")
  println(f"${doubleNum}%-20.2f--")

  println("------------")

  val aCharacter = 'u'
  println(f"$aCharacter%5c")
  // println(f"$aCharacter%05c")
  println(f"$aCharacter%-5c|")

  // %e, %i, %o, %u, %x, %%, $$
  // \b, \f, \r, \t, \u

  println("------------")

  val upper = for ch <- "This is a string." yield ch.toUpper
  println(upper)

  println("------------")

  "سلام hello".getBytes.map(c => f"$c%d ").foreach(print)
  println()

  println("------------")

  "SOMETHING".map {c =>
    (c.toByte + 32).toChar
  }.foreach(print)
  println()

  println("------------")

  val firstMatch = "[0-9]+".r.findFirstIn("address in 123 is 56.75 + 26")
  println(firstMatch)
  "[0-9]+".r.findAllIn("address in 123 is 56.75 + 26").toSet.foreach(println)

  println("------------")

  val patt = "([0-9]+) ([A-Za-z]+)".r
  val patt(count, fruit) = "1063 banana"
  println(count)
  println(fruit)

  println("------------")

  val moviesZipRE = "movies (\\d{5})".r
  val moviesNearCityStateRE = "movies near ([a-z]+), ([a-z]{2})".r
  val userInput = "movies near boulder, co"
  val results = userInput match
    case moviesZipRE(zip) => println(zip)
    case moviesNearCityStateRE(city, state) => println(s"city: ${city}, state: $state")
    case _ => None

  println("------------")


  println("------------")

  val randStr = scala.util.Random.nextString(10)
  println(randStr)

  val myrand = scala.util.Random

  val randStr2 = myrand.alphanumeric.take(10)
  println(randStr2)

  val randStr3 = myrand.alphanumeric.take(15).mkString
  println(randStr3)

  val randStr4 = for i <- 0 to myrand.nextInt(20) yield myrand.nextPrintableChar  
  println(randStr4)

  val randStr5 = for i <- 0 to myrand.nextInt(20) yield myrand.nextPrintableChar  
  println(randStr5.mkString)

  println("------------")

