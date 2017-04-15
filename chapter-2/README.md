# Exercises

## 2.1

[Code](solution-2-1.c)

## 2.2

Missing

## 2.3

Missing

## 2.4

Both algorithms have same performance when the value less than equals the last
element on the array.

`busca-ord1(x)` has the advantage that before any loop it checks if x is less
than equals the n-th element which prevents us from searching an element that
obviously overflows the `max` element from the array.

## 2.5

Missing

## 2.6

[Code](solution-2-6.c)

## 2.7

[Code](solution-2-7.c)

## 2.8

[Code](solution-2-8.c)

## 2.9

[Code](solution-2-9.c)

## 2.10

[Code](solution-2-10.c)

## 2.11

Different from ordered lists, insertion should ask for the `i` index to put the
new node.

- The algorithm should transverse `i - 1` nodes.
- `prev` is the `i - 1`th node.
- `post` is `prev->next` pointer.
- `to_add` is the new node.
- Point `prev->next` to `to_add` and `to_add->next` to post.

The removal algoritm works as follows:

- The algorithm should transverse `i - 1` nodes.
- `prev` is the `i - 1`th node.
- `found` is `prev->next` pointer.
- `post` is `found->next` pointer.
- Point `prev->next` to `post`.
- Free `found`;

## 2.12

Using sequential allocation with ordered arrays:

- **Search**: You can binary search with O(logn) complexity.
- **Insert**: You can binary search the proper position `i` for the insertion.
  Still you'll have to move `n - i` elements positions.
- **Remove**: Same as insertion.

Using dynamic allocation with pointers:

- **Search**: You can't binary search, just transverse the list. O(n).
- **Insert**: Except the transversion, inserting is cheap as you only have to
  change pointers.
- **Remove**: Same as insertion.

There's no silver bullet when choosing between sequential or dynamic allocation.
Both have they strong and weak points.

## 2.13

[Code](solution-2-13.c)

## 2.14

[Code](solution-2-14.c)

## 2.15

[Code](solution-2-15.c)

## 2.16

[Code](solution-2-16.c)

## 2.17

[Code](solution-2-17.c)

## 2.18

[Code](solution-2-18.c)

## 2.19

Missing

## 2.20

[Code](solution-2-20.c)

## 2.21

[Code](solution-2-21.c)

The complexity is O(k) where K is the number of non-zero elements.
