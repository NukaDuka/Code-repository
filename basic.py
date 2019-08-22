import numpy as np

a = np.arange(10).reshape(5, 2)
print(a)
print(a.ndim)
print(a.shape)
print(a.dtype.name)

b = np.arange(5)
print(b)

x = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
c = np.array(x)
print(c)
print(c.ndim)
print(c.shape)
e = np.arange(5)
d = e.reshape(5, 1)
print(e)
print(d)
print((e@d)[0])
print(c[:, 0].T)
print(c.T)
f = c.copy()
print(np.vstack((c, f)))
print(np.hstack((c, f)))
print(np.column_stack((d, d)))
print(np.vstack((e, e)))
print (e > 2)

g = e > 2
h = e
h[g] = 69
print(h)