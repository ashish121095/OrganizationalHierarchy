Purpose of this Project
-----------------------------------------------------------------------------------------------------------------------------------------------
To implement a general tree data structure that can store, manipulate, and query the organizational chart for a company. The organizational chart contains the name, and title of every employee in the company. It also shows who works under whom within company.

Requirements
-----------------------------------------------------------------------------------------------------------------------------------------------
C++ Programming Language, General Tree Data Structure, Linked-list based Implementation or an Array-based implementation, Read from file

Assumptions
-----------------------------------------------------------------------------------------------------------------------------------------------
All titles are unique in the company,	One employee works under only one boss

About Project
-----------------------------------------------------------------------------------------------------------------------------------------------
I had to choose C++ as it was requirement for this project. C++ is very popular for object oriented programming and that's what 
I had to use. I had used General Tree Data Structure to achieve desire result in this project. There was two option of implementation
of general tree one was Linked List and other was an Array. Array-based implementation would be very complicated as I had to take care
of every pointer in the tree. So, I chose Linked List based implementation as it would be little bit easy to take care of pointers as 
compared to array-based implementation. Node contains two field one for name and one for title of the position. I had to read data from 
text file which was written one particular manner and had to store it into general tree according requirements it was little bit tricky
reading from file. I have successfully implemented hire, fire, size and many other functions. Hire function simply hire an employee as
a left child of pointed node. Beside this, I have implemented fire function based on title of the position. This function fires an 
employee whose title gets matched with passed argument. So, if the title is found the employee’s node in the tree is deleted and function 
returns true and all employees of the fired employee now work directly for the fired employee’s boss so I had to set all pointers of all 
employees of fired employee to its boss (e.g. all children of the deleted node become children of the deleted node's parent).
I have also implemented size function which simply returns total number of employees in the company.
