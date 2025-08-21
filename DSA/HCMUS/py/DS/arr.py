import array

arr = array.array('i',[12,3,45,5])

for i in range(0,4):
    print(arr[i],end=" ")
print("\r")
arr.append(12)

for i in range(0,5):
    print(arr[i],end=" ")
print("\r")
arr.insert(2,15)

for i in range(0,6):
    print(arr[i],end=" ")