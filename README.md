_This project has been created as part of the 42 curriculum by wipion_

In this project, we are going to reproduce the behavior of the function printf
while using a linked list.

for compiling this project i used cc and the flags : -Werror -Wextra -Wall.

Resources:
I didn't use linked list before, i used this site (https://www.geeksforgeeks.org/dsa/linked-list-data-structure/)
to learn and understand. 
i used this site to understand the macro va_arg(https://koor.fr/C/cstdarg/va_arg.wp).

In my printf function, i use the va_ macro in order to store the mutiples arguments in a list,
that initialise with va_start.

Then i create a linked_list, the each node of the list is goig to cointain those data:

- a caracter associated with the format '%(caracter)'

- a pointer on a function that will do the task assiocated with the caracter
and return the number of printed caracters with that function

after every flags has been executed, it will return the number printed by the functions
+ the number of caracter in the first string.

finally it will empty & the linked chain
 



