

with open("input.txt", "r") as f:
   data = f.read().splitlines()
training_data = []
outputs = []

for line in data:
   td, o = line.split(" | ")
   training_data.append(td.split())
   outputs.append(o.split())

def part_one():
   answer = 0
   for output in outputs:
      for word in output:
         if len(word) in [2, 3, 4, 7]:
            answer += 1
   return answer

def part_two():
   answer = 0
   freqs = []
   key = {42:"0", 17:"1", 34:"2", 39:"3", 30:"4", 37:"5", 41:"6", 25:"7", 49:"8", 45:"9"}
   for td in training_data:
      freq = {}
      for word in td:
         for c in word:
            if c not in freq.keys():
               freq[c] = 0
            freq[c] += 1
      freqs.append(freq)
   for i, output in enumerate(outputs):
      number = ""
      for word in output:
         score = 0
         for c in word:
            score += freqs[i][c]
         number += key[score]
      answer += int(number)
   return answer


print("part one", part_one())
print("part two", part_two())