class Set:
    def __init__(self, n):
        self.s = []
        for _ in range(n):
            e = int(input("Enter Element: "))
            if e not in self.s:
                self.s.append(e)
                
    def add(self, e):
        if e not in self.s:
            self.s.append(e)
    
    def delete(self, e):
        if e in self.s:
            self.s.remove(e)

    def intersect(self, s2):
        return list(set(self.s).intersection(s2))
    
    def union(self, s2):
        return list(set(self.s).union(s2))
    
    def diff(self, s2):
        return list(set(self.s).difference(s2))
    
    def subset(self):
        subsets = [[]]
        for ele in self.s:
            new_subsets = [subset + [ele] for subset in subsets]
            subsets.extend(new_subsets)
        return subsets

def create_set():
    n = int(input("Enter Total Number of Elements: "))
    s = Set(n)
    return s

print("Creating Set 1")
s1 = create_set()
print("Set 1:", s1.s)

print("Creating Set 2")
s2 = create_set()
print("Set 2:", s2.s)

while True:
    print("\n1.Add")
    print("2.Remove")
    print("3.Contain")
    print("4.Size")
    print("5.Intersection")
    print("6.Union")
    print("7.Difference")
    print("8.All possible subsets of the set")
    print("0.Exit")
    ch = int(input("Enter Choice: "))

    if ch == 1:
        ele = int(input("Enter Element: "))
        s1.add(ele)
        print("Set 1:", s1.s)

    elif ch == 2:
        ele = int(input("Enter Element in Set 1: "))
        s1.delete(ele)
        print("Set 1:", s1.s)

    elif ch == 3:
        ele = int(input("Enter Element: "))
        if ele in s1.s:
            print("Element is present in Set 1")
        else:
            print("Element is not present in Set 1")

    elif ch == 4:
        print("The Size of the Set 1 is", len(s1.s))
    
    elif ch == 5:
        s3 = s1.intersect(s2.s)
        print("Intersection:", s3)
    
    elif ch == 6:
        s3 = s1.union(s2.s)
        print("Union:", s3)
    
    elif ch == 7:
        print("s1-s2: ", s1.diff(s2.s))
        print("s2-s1: ", s2.diff(s1.s))
    
    elif ch == 8:
        subsets = s1.subset()
        print("All the Subsets of the Set :")
        for subset in subsets:
            print(subset)
    
    elif ch == 0:
        break

    else:
        print("Wrong Choice")
