from ctypes import *


belka = CDLL('./DLL1.dll')


belka.Distance.argtypes = (POINTER(c_double), POINTER(c_double), c_int)
belka.Distance.restype = c_double

belka.timeD.argtypes = (POINTER(c_double), POINTER(c_double), c_int, c_int)
belka.timeD.restype = c_double


n = 3
a = (c_double * n)(1.0, 2.0, 3.0)
b = (c_double * n)(4.0, 5.0, 6.0)


rast = belka.Distance(a, b, n)
print("Расстояние между векторами =", rast)


