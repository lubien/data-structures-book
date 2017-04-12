# Exercises

## 1.1

Every recursive algorithm must have a base case otherwise it would recurse
undefinetly and therefore it would never stop, contrary to 'algorithm'
definition that claims that it should have a finite amount of steps.

## 1.2

### (i)

The claim is false because the Algorithm 1.2 is not tail-call recursive and
keeps increasing memory usage each recursive in the form of

```
3 . fact(2)
3 . 2 . fact(1)
3 . 2 . 1
```

So only when it reaches the base step it'll do all the multiplications.

### (ii)

The claim is true because it stores from 0..n (n + 1) elements into the `f`
array.

## 1.3

[Code](solution-1-3.c)

## 1.4

When n is 1, the solution is straightforward, just one movement. 2¹ - 1 = 1.

When n is 2, there's one movement and two recursive calls to n - 1, which both
have n equal 1 and do only one move as seen before.
That gives us 3 moves.
2² - 1 = 3.

When n is 3, there's one movement and two recursive calls to n - 1, which both
have n equal 2 and do 3 moves as seen before.
That gives us 1 + 3 + 3 = 7 moves.
2³ - 1 = 3.

By extension, any hanoi call of n requires 1 + 2 * (number of calls for n - 1) calls, which is 2^n - 1 calls.

```
# n = 2

    han(2)
 han(1) han(1)

# n = 3

             han(3)
    han(2)          han(2)
 han(1) han(1)   han(1) han(1)
```

## 1.5

Missing

## 1.6

When n is 1, it only requires one movement to finish the task.
Therefore hanoi(1, A, B, C) is correct.

When n > 1, it requires one call moving the topmost n - 1 to an spare tower,
move the bottom remainder disk to the target then moving the spare tower members
to the target.
Since the bottom one is larger than any in the spare the algorithm is correct.

## 1.7

[Code](solution-1-7.c)

This lower the number of recursive calls by 2^n.

## 1.8

[Code](solution-1-8.c)

