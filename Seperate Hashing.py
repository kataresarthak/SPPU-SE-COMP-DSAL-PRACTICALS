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

ch = 'y'
obj = SeparateHash(10)

while ch in ('y', 'Y'):
    print("\n1.INSERT ELEMENT\n2.FIND KEY\n3.DISPLAY ELEMENT\n4.DELETE ELEMENT")

    n = int(input("ENTER YOUR CHOICE: "))
    if n == 3:
        obj.display_hash()
    elif n == 2:
        key = int(input("ENTER ELEMENT TO FIND: "))
        print("ELEMENT FOUND AT INDEX:", obj.get_hash_index(key))
    elif n == 1:
        num = int(input("HOW MANY ELEMENTS YOU WANT TO INSERT: "))
        for _ in range(num):
            key = int(input("ENTER ELEMENT TO INSERT: "))
            obj.add(key)
    elif n == 4:
        key = int(input("ENTER ELEMENT TO DELETE: "))
        obj.delete(key)
    ch = input("DO YOU WANT TO CONTINUE (Y OR N): ")
