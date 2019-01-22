# pascalTriangle
A console program in c++, which prints elements of Pascal's Triangle, that are dividable by given numbers

The best way to use the program is to set the size of console buffer to maximum, set background color to white and font size to the minimum.

The program needed to contain a set of functions, operating on numbers saved as std::string. The numbers in the further parts of Pascal's Triangle no longer fit into any of numeric variables in c++.

The size of the triangle caused a need to display text in the smallest font-size possible. The text was no longer readible so i had to find a way of printing texts in multiple collumns.

Warning:

In the very beginning the program takes some time to count all the elements of Pascal's Triangle untill 499th line. It can take several minutes. Later on it uses the triangle once counted.
