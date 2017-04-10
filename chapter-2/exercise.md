# Exercises

## 2.1

[Code](solution-1-3.c)

## 2.2

Given that the probability of finding the key at the k-th element of the
non-ordered list equals half of the probability of the next one except the last:

p(n)     = q     = 2⁰
p(q - 1) = q / 2 = 2¹
p(n - 2) = q / 4 = 2²
...
p(k)     = q / 2^(n - k)

Knowing that, the other values came from the book example.

p(find k)        = q / (2^(n - 1))
p(do not find k) = 1 - q

t(find k)        = k
t(do not find k) = n

The put these values at the average complexity formula and do the math.

## 2.3

Pretty much the same as before except that besides p(find k) you need to the the
proper values to an sorted array (which are in the book too) then do the math.

## 2.4

Both algorithms have same performance when the value less than equals the last
element on the array.

`busca-ord1(x)` has the advantage that before any loop it checks if x is less
than equals the n-th element which prevents us from searching an element that
obviously overflows the `max` element from the array.
