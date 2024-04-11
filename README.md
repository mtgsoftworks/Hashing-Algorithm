# Hashing-Algorithm
As part of the assignment, example data from two different classes found in the file project1.xlsx needs to be placed in a table with two different index values using the hashing approach. When the hashing function is executed, data with the A label should be placed in the first index, and data with the B label should be placed in the second index.

For this process, a mathematical formula has been used to transform long data in the dataset into a manageable output:
Formula = Most frequently occurring number in the array / Total number of data in the array

In the generated hash table, index 0 is used for the A label and index 1 is used for the B label. Each dataset is transferred to an array, and using the formula above, an output is obtained for each. The obtained comma-separated outputs are stripped of commas to allow the hash functions to work with integers, and the first 9 digits of the number are taken to optimize them to avoid exceeding the maximum value range of the integer data type (2,147,483,647) and prevent memory overflows.

Then, the maximum-minimum (max-min) range is calculated for A-labeled data and a separate max-min range is calculated for B-labeled data. The function calculating the hash code is written to return 0 for the A group in the range of 256,976,744 - 361,788,617, and 1 for the B group in the range of 230,272,265 - 283,549,783. Thus, for 16 data labeled A, the output of the hash function is 0, and for 6 data labeled B, it returns 1. All data is added to the generated hash table, and as the final output, the hash table along with the hash codes for each data are printed on the screen.
