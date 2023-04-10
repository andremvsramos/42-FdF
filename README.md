# 42_FdF
FdF Project - 42 School (Porto)

This is my FdF project from the 42 School Common Course.

The basis of this project is to be able to read a matrix map and display it in a 3D environment.
The map file must be made of numbers (as per the examples in /test_maps directory),
declaring length and width using the number of lines and length of the first line of the .fdf file.
The Z-axis will be determined by the value of the [x][y] position of the matrix.

My adaptation of the project allows switching between 3D and 2D (topdown) views, movement and rotation (to some degree). It also offers a simple color grade.

Using this software, you can display any map you wish, big or small, provided you use an .fdf type map.

The graphics library used is MiniLibX, a in-house graphics library made by the school. As it is, there are some quirks with it (breaking functions,|
leaking functions, etc...). For more detailed documentation, please visit: https://harm-smits.github.io/42docs/libs/minilibx
