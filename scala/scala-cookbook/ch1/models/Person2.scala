package foo

class Person(val name: String):
  override def toString = name

// :load models/Person2.scala
// fails, since cannot load .scala file containing package information
