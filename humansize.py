def approx_size(size, is1024 = False):
    ''' Convert a number into human-readable form.

        Keyword arguments:

        size -- file size in bytes
        is1024 -- if False(default), division takes place by 1000
                  if True, division takes place by 1024
        
        Returns: String
    '''
    if size < 0:
        raise ArithmeticError('Number must be greater than 0.')
    
    suffix = {1000 : ['KB', 'MB', 'GB', 'TB', 'PB', 'EB', 'ZB', 'YB'],
          1024 : ['KiB', 'MiB', 'GiB', 'TiB', 'PiB', 'EiB', 'ZiB', 'YiB']}
    
    div = 1024 if is1024 else 1000

    idx = 0
    for idx in range(0, len(suffix[div])+1):
        if size < div:
            break
        
        size /= div
    else:
        raise ArithmeticError('Number too large.')
    
    return 'The size is {0:.2f} {1}'.format(size, suffix[div][idx-1])

if __name__ == '__main__':
    print(approx_size(1000))
    print(approx_size.__doc__)