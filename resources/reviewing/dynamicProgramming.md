# 2 lines of production

* f1[j] = min(f1[j-1] + a1[j], f2[j-1] + t21[j-1] + a1[j])
* Define the lowest cost up to a station recursively.

# Matrix multiplication
* min(m[i,k] + m[k+1,j] + p[i-­1] . p[k] . p[j], m[i,j])
