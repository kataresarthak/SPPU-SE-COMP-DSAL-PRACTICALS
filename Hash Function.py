class SeparateHash:
    def __init__(self, n):
        self.n = n
        self.v = [[] for _ in range(n)]

    def get_hash_index(self, x):
        return x % self.n

    def add(self, x):
        i = self.get_hash_index(x)
        if x not in self.v[i]:
            self.v[i].append(x)

    def find(self, x):
        i = self.get_hash_index(x)
        if x in self.v[i]:
            print("ELEMENT FOUND AT INDEX :", obj.get_hash_index(x))
        else:
            print("NO ELEMENT FOUND!")

    def delete(self, x):
        i = self.get_hash_index(x)
        if x in self.v[i]:
            self.v[i].remove(x)
            print(x, "DELETED")
        else:
            print("NO ELEMENT FOUND!")

    def display_hash(self):
        for i in range(self.n):
            print(i, end=" --> ")
            for j in self.v[i]:
                print(j, end=" ")
            print()

obj = SeparateHash(10)

while True:
    print("\n1.INSERT ELEMENT\n2.DISPLAY ELEMENT\n3.FIND KEY\n4.DELETE ELEMENT\n0.EXIT")
    ch = int(input("ENTER YOUR CHOICE :"))

    if ch == 1:
        num = int(input("HOW MANY ELEMENTS YOU WANT TO INSERT :"))
        for _ in range(num):
            key = int(input("ENTER ELEMENT TO INSERT :"))
            obj.add(key)

    elif ch == 2:
        obj.display_hash()

    elif ch == 3:
        key = int(input("ENTER ELEMENT TO FIND :"))
        obj.find(key)

    elif ch == 4:
        key = int(input("ENTER ELEMENT TO DELETE :"))
        obj.delete(key)
        
    elif ch == 0:
        break

    else:
        print("Wrong Choice")
