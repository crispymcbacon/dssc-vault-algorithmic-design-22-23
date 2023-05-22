from a_sortingalgorithms import merge_sort

def main():
    A=[5,2,4,6,1,3]
    merge_sort(A, 0, len(A) - 1)
    print(A)


if __name__ == "__main__":
    main()