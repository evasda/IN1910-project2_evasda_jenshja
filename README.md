# project2_evasda_jenshja

#### *__Initial notes to grader:__* 
+ __URL to project:__ https://github.uio.no/IN1910/project2_evasda_jenshja
+ __Compiler:__ Visual Studio 2017 Developer Command Prompt v15.0 was used in a ".sublime-build"-file. This file runs the "cl"-command. 


### __3__

| Call                    | ArrayList     | LinkedList    | Comment   |
| ----------------------- | ------------- | ------------- | ----------|
| get element i by index  | ![O(1)](https://latex.codecogs.com/gif.latex?%5Cmathcal%20O%281%29)  | ![O(i)](https://latex.codecogs.com/gif.latex?%5Cmathcal%20O%20%28i%29)| AL: [] accesses ith element directly. LL: using get_node() to get element i. |
| insert front            | ![O(n)](https://latex.codecogs.com/gif.latex?%5Cmathcal%20O%28n%29)  | ![O(1)](https://latex.codecogs.com/gif.latex?%5Cmathcal%20O%281%29)| AL: using insert() need to copy entire list. LL: create new node and set new head in insert(). |
| insert back (append)    | ![O(n)](https://latex.codecogs.com/gif.latex?%5Cmathcal%20O%28n%29)/![O(1)](https://latex.codecogs.com/gif.latex?%5Cmathcal%20O%281%29)  | ![O(1)](https://latex.codecogs.com/gif.latex?%5Cmathcal%20O%281%29)| AL: if resize is used => O(n), if not => O(1). LL: can append to tail. |
| insert into middle      | ![O(n)](https://latex.codecogs.com/gif.latex?%5Cmathcal%20O%28n%29)  | ![O(i)](https://latex.codecogs.com/gif.latex?%5Cmathcal%20O%20%28i%29)| AL: using insert() need to to copy entire list. LL: using get_node() to get element i-1. |
| remove from front       | ![O(n)](https://latex.codecogs.com/gif.latex?%5Cmathcal%20O%28n%29)  | ![O(1)](https://latex.codecogs.com/gif.latex?%5Cmathcal%20O%281%29)| AL: need to copy entire list. LL: access with get_node(i) when i=0. |
| remove from back        | ![O(n)](https://latex.codecogs.com/gif.latex?%5Cmathcal%20O%28n%29)  | ![O(n)](https://latex.codecogs.com/gif.latex?%5Cmathcal%20O%28n%29)| AL: need to copy entire list. LL: access get_node(i) twice, when first i=n and then i=n-1 |
| remove from middle      | ![O(n)](https://latex.codecogs.com/gif.latex?%5Cmathcal%20O%28n%29)  | ![O(i)](https://latex.codecogs.com/gif.latex?%5Cmathcal%20O%20%28i%29) | AL: need to copy entire list. LL: access get_node(i) twice, when first i=i and then i=i-1. |
| print                   | ![O(n)](https://latex.codecogs.com/gif.latex?%5Cmathcal%20O%28n%29)  | ![O(n)](https://latex.codecogs.com/gif.latex?%5Cmathcal%20O%28n%29)| AL: iterates entire list. LL: iterates entire list. |

### __4g)__
To survive the Josephus problem with n=68 and k=7 you should choose place number 68.

#### Further comment: 
As Eva had trouble with her computer(primarily with the C++ compiler), (almost) all work has been done by use of pair programming on Jens' computer, and has been commited through his git account. We have tried to mark the commits that both have contributed to with "from session", but we might have forgotten to do so at times.