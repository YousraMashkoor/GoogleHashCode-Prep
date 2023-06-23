from collections import Counter, defaultdict


class TrafficSignaling:

    def __init__(self, file):
        self.time = None
        self.TotalIntersections = None
        self.TotalStreets = None
        self.TotalCars = None
        self.points = None

        self.street = []
        '''
            [
                {
                    name: 'rue-de-londres,
                    start: 2,
                    end: 3,
                    time: 1
                },
            ]
        '''
        self.carPath = []
        '''
            [
                {
                    'street' = [a,v,b],
                    totalStreet = 3

                }
            ]
        '''
        self.filename = file

    def read_input(self):

        f = open('./input/{}.txt'.format(self.filename), 'r')
        time, TotalIntersections, TotalStreets, TotalCars, points = map(int, f.readline().strip().split(" "))

        for _ in range(TotalStreets):
            self.street.append(list(map(lambda ele : int(ele) if ele.isdigit()
          else ele, f.readline().strip().split(" "))))

        for _ in range(TotalCars):
            data = f.readline().strip().split(" ")
            carPath = {
                "streets": int(data[0]),
                "totalStreet": data[1:]
                }
            self.carPath.append(carPath)
        
        
        

        # for _ in range(0, cus):
        #     l = f.readline().strip().split(" ")
        #     d = f.readline().strip().split(" ")
        #     self.likes.update(list(l)[1:])
        #     self.dislikes.update(list(d)[1:])
        f.close()

    def output(self, ingredients):
        f = open('output/{}_output.txt'.format(self.filename), 'w')
        f.write(str(len(ingredients)))
        f.write(" ")
        f.write(" ".join(ingredients))
        f.close()


    def top_5_ingredients(self):
        self.read_input()

        # ingredients = []
        # for x in self.likes.most_common():
        #     if self.likes[x[0]] > self.dislikes[x[0]]:
        #         ingredients.append(x[0])

        # self.output(ingredients)


if __name__ == '__main__':
    for x in ['a']:
        TrafficSignaling(x).top_5_ingredients()
