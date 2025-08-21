import sys
def selectionSort(a):
    b = []

    while len(a):
        b.append(min(a))
        a.remove(min(a))
    
    return b

def main():
    list = [1,3,41,5,2,55,2,3,23]
    print(list)
    print(" ")
    list = selectionSort(list)
    print(list)
main()




