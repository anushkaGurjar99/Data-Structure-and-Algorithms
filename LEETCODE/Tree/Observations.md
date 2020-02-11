### Global variables in Recursion? 

- make sure no one else is calling the method in a parallel thread,
- make sure that the list variable has been initialized,
- make sure that the list doesn't already contain anything else, and
- remember to read off the list when you're done with it.

If you forget to do any of these, your program will not behave as expected, but you won't get any 
compiler errors indicating this. This makes the code harder to use correctly and increases the chances 
that you'll get more bugs in your program.
________________________________________________________________________________________________________________
