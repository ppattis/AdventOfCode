#
#  Advent of Code 2018
#  Day 13
#
#  By PatchesTheDipstick
#

def getInput(file_name):
   data = []
   with open(file_name) as input_file:
      data = input_file.read().splitlines()
   return data

class Point(object):
   def __init__(self, x, y):
      self.coord = (x, y)

   def __str__(self):
      return "({0}, {1})".format(self.coord[0], self.coord[1])

   def __add__(self, other):
      return (self.coord[0] + other.coord[0], self.coord[1] + other.coord[1])

   def getPos(self):
      return (self.coord[0], self.coord[1])


class Cart(object):
   def __init__(self, x, y, dir, id):
      self.pos = Point(x, y)
      if dir == "<":
         self.dir = Point(-1, 0)
      elif dir == "^":
         self.dir = Point(0, -1)
      elif dir == ">":
         self.dir = Point(1, 0)
      elif dir == "v":
         self.dir = Point(0, 1)
      self.id = id

   def __lt__(self, other):
      if self.pos.coord[1] < other.pos.coord[1]:
         return True
      elif self.pos.coord[1] == other.pos.coord[1] and self.pos.coord[0] < other.pos.coord[0]:
         return True
      return False

   def __str__(self):
      return("({}, {}) facing ({}, {})".format(self.pos.coord[0], self.pos.coord[1], self.dir.coord[0], self.dir.coord[1]))

   def getPos(self):
      return self.pos.getPos()

   def move(self, grid, carts):
      print(grid[self.getPos()])
      self.pos += self.dir
      if grid[self.getPos()] == "/":
         x = self.dir.coord[0]
         y = self.dir.coord[1]
         x *= -1
         y *= -1
         self.dir.coord = (y, x)
      elif grid[self.getPos()] == "\\":
        x = self.dir.coord[0]
        y = self.dir.coord[1]
        self.dir.coord = (y, x)

def collision(carts):
   for x in range(len(carts)):
      for y in range(x, len(carts)):
         if carts[x].pos == carts[y].pos and carts[x].id != carts[y].id:
            return True
         else:
            return False

def getCollision(carts):
   for x in range(len(carts)):
      for y in range(x, len(carts)):
         if carts[x].pos == carts[y].pos and carts[x].id != carts[y].id:
            return carts[x].pos


if __name__ == '__main__':
   
   data = getInput("input.txt")
   grid = {}
   carts = []
   cart_id = 0
   for y, line in enumerate(data):
      for x, char in enumerate(line):
         if char in ["<", ">", "^", "v"]:
            carts.append(Cart(x, y, char, cart_id))
            if char in ["<", ">"]:
               grid[(x, y)] = "-"
            else:
               grid[(x, y)] = "|"
         elif char in ["-", "|", "/", "\\"]:
            grid[(x, y)] = char

   for cart in carts:
      print(cart)
   while not collision(carts):
      carts.sort()
      for cart in carts:
         cart.move(grid, carts)

   print("Advent of Code 2015 Day 02")
   print("  Part one:", getCollision(carts))
   print("  Part two:", ribbon)  
   
