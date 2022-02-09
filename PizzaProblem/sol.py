from collections import Counter


class OnePizza:

    def __init__(self):
        self.likes = Counter()
        self.dislikes = Counter()
        self.c = None


    def read_input(self):
        f = open('input.txt', 'r')
        self.c = int(f.readline())

        for x in range(0, self.c):
            l = f.readline().strip().split(" ") # l=['2', 'mushrooms', 'tomatoes']
            d = f.readline().strip().split(" ") # d=[1, 'Basil']

            self.likes.update(l[1:])
            self.dislikes.update(d[1:])

        f.close()

    def solution(self):
        self.read_input()
        ingredients = []

        for x in self.likes:
            if self.likes[x] > self.dislikes[x]:
                ingredients.append(x)

        self.output(ingredients[:5])


    def output(self, ingredients): # ingredients=['mushrooms', 'tomatoes']
        f = open('output.txt', 'w')
        f.write(str(len(ingredients)))
        f.write(" ")
        f.write(" ".join(ingredients))
        f.close()

if __name__ == '__main__':
    OnePizza().solution()