input()
w = raw_input()
w = (w
  .lower()
  .replace("b", "1").replace("c", "1")
  .replace("t", "3").replace("j", "3")
  .replace("l", "5").replace("v", "5")
  .replace("p", "7").replace("m", "7")
  .replace("n", "9").replace("g", "9")
  .replace("d", "2").replace("w", "2")
  .replace("f", "4").replace("q", "4")
  .replace("s", "6").replace("x", "6")
  .replace("h", "8").replace("k", "8")
  .replace("z", "0").replace("r", "0")
  .replace("a", "").replace("i", "").replace("u", "").replace("e", "").replace("o", "").replace("y", "").replace(".", "").replace(",", ""))
for i in range(10):
  w = w.replace("  ", " ")
w = w.strip()
print w
