def pivot(arr,left,right):
    pivot = arr[0]
    left = []
    right = []
    for i in range(len(arr)):
        if arr[i] < pivot:
            left.append(arr[i])
            arr.remove(arr[i])
        if arr[i] > pivot:
            right.append(arr[i])
            arr.remove(arr[i])
    for i in range(len(left)): arr.append(left[i])
    arr.append(pivot)
    for i in range(len(right)): arr.append(right[i])

def quickSort(arr,left,right):
    if left >= right:
        return
    pivot = pivot(arr,left,right)
    quickSort(arr,left,pivot-1)
    quickSort(arr,pivot+1,right)

def main():
    l = [1, 3, 41, 5, 2, 55, 2, 3, 23]
    print(l)
    quickSort(l)
    print(l)

main()
