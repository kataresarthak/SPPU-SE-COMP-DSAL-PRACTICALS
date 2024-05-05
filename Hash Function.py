HT = [[] for _ in range(10)]
print("Blank = ",HT)

def insert(HT, key, value):
    loc = key % 10
    bucket = HT[loc]
    exist = False
    for i,kv in enumerate(bucket):
        k,v = kv
        if key == k:
            exist = True
            break
    if exist:
        bucket[i] = (key, value)
    else:
        bucket.append((key, value))

def delete(HT,key):
    loc = key % 10
    bucket = HT[loc]
    exist = False
    for i,kv in enumerate(bucket):
        k,v = kv
        if key == k:
            exist = True
            break
    if exist:
        del bucket[i]
        print("Element is deleted")
    else:
        print("Element not found")

def search(HT,key):
    loc = key % 10
    bucket = HT[loc]
    exist = False
    for i,kv in enumerate(bucket):
        k,v = kv
        if key == k:
            exist = True
            break
    if exist:
        print("Element found, value :",v)
    else:
        print("Element not found")

def display(HT):
    for i,bucket in enumerate(HT):
        print("Bucket",i,"Elements:",bucket)

while True:
    print("\n1.Insert key & Value")
    print("2.Delete")
    print("3.Search")
    print("4.Print Hash Table")
    print("0.Exit")
    ch = int(input("Enter Choice :"))

    if ch == 1:
        key = int(input("Enter key to insert :"))
        value = input("Enter value to insert :")
        insert(HT, key, value)
    elif ch == 2:
        key = int(input("Enter the key to delete :"))
        delete(HT, key)
    elif ch == 3:
        key = int(input("Enter the key to search :"))
        search(HT, key)
    elif ch == 4:
        display(HT)
    elif ch == 0:
        break
    else:
        print("Wrong Choice")
        
