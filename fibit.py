class Fib:

    def __init__(self, max):
        self.max = max
    
    def __iter__(self):
        self.a = 0
        self.b = 1
        return self
    
    def __next__(self):
        ret = self.a
        if ret > self.max:
            raise StopIteration
        
        self.a, self.b = self.b, self.a + self.b
        return ret


if __name__ == '__main__':
    for i in Fib(1000):
        print(i)
