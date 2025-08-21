def heapify(arr,i,size):
    max = i
    left = 2*i+1
    right = 2*i+2
    if left < size and arr[left] > arr[i]:
        max = left
    if right < size and arr[right] > arr[i]:
        max = right
    if i != max:
        arr[i], arr[max] = arr[max], arr[i]
        heapify(arr,max,size)

def heapSort(arr):
    for i in range(int(len(arr)/2-1), -1, -1):
        heapify(arr,i,len(arr))

    for i in range(len(arr) - 1,-1,-1):
        arr[i],arr[0] = arr[0],arr[i]
        heapify(arr,0,i)
        
def main():
    l = [1, 3, 41, 5, 2, 55, 2, 3, 23]
    print(l)
    heapSort(l)
    print(l)

main()