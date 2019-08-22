def printalot(*args):
    print(args)
    for s in args:
        print(s, end='\n')

if __name__ == '__main__':
    printalot('This is a line', 'This is another line', 'THis is a third line', 'Bye')
