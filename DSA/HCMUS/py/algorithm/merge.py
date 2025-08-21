def merge(arr,left,mid,right):
    i = left
    j = mid + 1
    length = right - left + 1
    temp  = []
    while i <= mid and j <= right:
        if arr[i] <= arr[j]:
            temp.append(arr[i])
            i += 1
        else:
            temp.append(arr[j])
            j += 1
    while i <= mid:
        temp.append(arr[i])
        i += 1
    while j <= right:
        temp.append(arr[j])
        j += 1

    for i in range(length):
        arr[left + i] = temp[i]
    

def mergeSorted(arr,left,right):
    if left >= right:
        return

    mid = (left + right) // 2
    mergeSorted(arr, left, mid)
    mergeSorted(arr, mid + 1, right)
    merge(arr, left, mid, right)

def main():
    l = [1, 3, 41, 5, 2, 55, 2, 3, 23]
    for v in l:
        print(v, end=" ")
    print()
    mergeSorted(l, 0, len(l) - 1)
    for v in l:
        print(v, end=" ")

main()