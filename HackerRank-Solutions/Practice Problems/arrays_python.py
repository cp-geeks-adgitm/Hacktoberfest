import numpy


def arrays(arr):
    # arr[::-1] will reverse the list
    return numpy.array(arr[::-1], float)


if __name__ == '__main__':
    arr = input().strip().split(' ')
    result = arrays(arr)
    print(result)