class SeparateHash:
    def __init__(self, n):
        self.n = n
        self.v = [[] for _ in range(n)]

    def getHashIndex(self, x):
        return x % self.n

    def add(self, x):
        i = self.getHashIndex(x)
        if x not in self.v[i]:
            self.v[i].append(x)

    def del_(self, x):
        i = self.getHashIndex(x)
        if x in self.v[i]:
            self.v[i].remove(x)
            print(f"{x} deleted!")
        else:
            print("No Element Found!")

    def displayHash(self):
        for i, bucket in enumerate(self.v):
            print(f"{i} -> {' '.join(map(str, bucket))}")

obj = SeparateHash(10)

while (ch := input("Do you want to Continue? (y/n): ").lower()) == 'y':
    print("1.Insert the element\n2.Find the Key element\n3.Display all element\n4.Delete key element")
    choice = int(input("Enter your Choice: "))
    
    if choice == 1:
        for _ in range(int(input("How many elements do you want to insert?: "))):
            obj.add(int(input("Insert the Element: ")))
    elif choice == 2:
        print("Element at index:", obj.getHashIndex(int(input("Enter element to find: "))))
    elif choice == 3:
        obj.displayHash()
    elif choice == 4:
        obj.del_(int(input("Delete: ")))
