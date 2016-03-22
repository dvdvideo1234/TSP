# TSP ( Tensor State Processing )

This project is an implementation of a vector processing C++ class.

```
I made this thing as a huge C++ example for a lecture

You can create tensors ( 3D arrays of vectors ), trajectories ( lists of vectors ),
name your points in space ( by calling setName() ), attach you own data to a vector ( using setUser() ).

What makes this vector processing library different is that it's very intuitive.

Supports every 32-bit MCU capable of floating point arithmetic
Contains every 3D-space vector application you can think of.
Supports coding effective friend operators. For example:
  A *= B ( A = A * dot_product ( A and B ) ) data remains in A
  A ^= B ( A = cross_product ( A and B ) ) data remains in A
  V++ Post-incrementing ( or decrementing ) a vector with its own direction.
  ++V Pre-incrementing ( or decrementing ) a vector with its own direction.
  ( And so on .. )
Supports irrelevant or non-defined operations skipping. For example:
  Direction cannot be calculated when origin vector's length is zero
  Angle between vectors cannot be calculated when either of the vector's length is zero
  There is a check for value different than zero before a division
  When a method contains a pointer parameter, NULL check is preformed
  ( And so on .. )
The V:Set() method, when called with no parameters, resets x, y and z.
Methods with prefix "get" return something.
Methods starting with capital letter affect the object they are call on.

You can view the "main.cpp" for tutorial how to use the library.
```
