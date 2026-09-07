
class Foo:
    def __init__(self):
        self.a = 10

    def boo(self):
        print("boo")

class Boo:
    def __init__(self):
        self.a = 10

    def boo(self):
        print("boo")

def foo(obj):
    print(obj.a)
    obj.boo()

def main():
    f = Foo()
    b = Boo()
    foo(f)
    foo(b)
    foo(10)

if __name__ == "__main__":
    main()
