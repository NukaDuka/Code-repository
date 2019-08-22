
def fib1(n):
    '''
    Prints out all fibonacci numbers less than or equal to the given number.

    Keyword arguments:

    n -- Upper limit of the fibonacci sequence

    Returns: nothing
    '''
    a, b = 0, 1
    while a < n:
        print(a)
        a, b = b, a+b
    print()


def fib2(n):
    a, b = 0, 1
    result = []
    while a < n:
        result.append(a)
        a, b = b, a+b
    return result

if __name__ == '__main__':
    print('whatchu doin here m8 git out ya cant')
    fib1(1000)