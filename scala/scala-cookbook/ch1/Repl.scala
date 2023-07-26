import sys.process.*

def clear = "clear".!
def cmd(cmd: String) = cmd.!!
def ls(dir: String) = println(cmd(s"ls -al $dir"))

// scalac Repl.scala
// scalac
// Now you can run clear, cmd, ls inside REPL
// clear
// cmd("ls /tmp")
// ls("../")
