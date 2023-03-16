<img width="150px" src="https://www.nscc.ca/img/aboutnscc/visual-identity-guidelines/artwork/nscc-jpeg.jpg" >

# PROG 2400 - Exercise 4


### Task
We  are given code in the **main.cpp** file which already links in and creates a *LinkedList* object, which is defined in the **linked_list.hpp** file. The *LinkedList* class also uses a *Node* object, which is defined in **node.hpp**.  

Today our nodes will hold **string values** as opposed to integers. Of course, we can store any data type we like as the "*payload*" of our Linked List nodes.

Your job is to implement the methods that are stubbed in in the **linked_list.cpp** file in order to achieve the desired output, shown below. Be aware the new *insertAtLocation()* and *deleteAtLocation()* functions should return the Node that is created or deleted, or a nullptr if they fail (i.e. the index is out of range).  The *print()* function today should output a final "*NULL*" for the end of the list itself, rather than rely on main. Also, the *destructor* for the LinkedList should delete all the node objects in the list.

The only change you should need to make in **main.cpp** should be to report the **Big O analysis** of the time complexity of each LinkedList operation in the appropriate output messages.

Only the **main.cpp** and **linked_list.cpp** files should be modified.
  
The image below shows the final expected output (with Time Complexity hidden):

<img width="600px" src="https://prog2400.netlify.app/ex4-output.png" alt="EX4 Output">

### Instructions:
-   Clone this repository to your local machine, make changes in CLion so all tests pass, and then commit and push the entire project up to GitHub
-   You should then be able to see your raw score on GitHub out of 10 as shown in class. The final grade will depend on the time of submission, see below:

#### Marking Scheme
Final Grade | Requirement
:---: | ---
|**10/10** | Exercise is correct (passes all tests) and is completed within the allotted in-class time.
|**8/10** | Exercise is correct (passes all tests) and is completed within a 12-hour grace period beginning immediately following the end of in-class time.
|**6/10** | Exercise is correct (passes all tests) and is completed and submitted after the 12-hour grace period has elapsed.
|**0/10** | Exercise is not submitted or does not pass all tests.

> Written with [StackEdit](https://stackedit.io/).
