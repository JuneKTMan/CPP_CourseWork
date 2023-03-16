<img width="150px" src="https://www.nscc.ca/img/aboutnscc/visual-identity-guidelines/artwork/nscc-jpeg.jpg" >

# PROG 2400 - Exercise 9


### Task
We  are given code in the **main.cpp** file which already links in and creates a *SelfBalancedBST* object, which is defined in the **selfBalancedBST.hpp** file. The *SelfBalancedBST* class also uses a *Node* object, which is defined in **node.hpp** and this time the Node holds an **integer** value and has been modified to have **pointers to the left and right branch nodes** of the tree. 

You can use either an **AVL Tree** or a **Red-Black Tree** to implement your *SelfBalancedBST* object, while adding any necessary private methods to the **selfBalancedBST.hpp**  and **selfBalancedBST.cpp** files. 

You may want to follow one of the following tutorials, which are quite good, even if they are in Java:

https://www.happycoders.eu/algorithms/avl-tree-java/

https://www.happycoders.eu/algorithms/red-black-tree-java/

You may certainly reuse code from Exercise 8 for basic inserts and searches in a Binary Search Tree.

You may need to also add appropriate extra properties to the **Node** to support AVL or Red-Black tree operations depending on your chosen implementation.

Your job is to implement the methods that are stubbed in in the **selfBalancedBST.cpp** file in order to achieve the desired output, shown below. Do not modify the provided **print** functions, other than to print some extra information for your chosen tree implementation as explained below.

While you can use either the AVL or Red-Black tree to implement the solution, you may want to modify the provided print functions a bit to output red nodes in a Red-Black tree in red or to output the tree height for an AVL tree.

If doing a Red-Black tree and wanting to print colours, try the following:

 1. Follow this example to use ANSI colours at the terminal: https://www.theurbanpenguin.com/4184-2/
 
 2. In order to get ANSI colors showing in CLion Run Console we need to do the following routine:
	 1. Choose Help -> Edit Custom Properties from CLion menu
	 2. Add the following lines to the idea.properties file:
			 *run.processes.with.pty=false
		
	 3. Restart CLion.
	 4.  Reference: https://youtrack.jetbrains.com/issue/CPP-8395/Registry-setting-runprocesseswithpty-not-saved#focus=Comments-27-2499735.0-0
  
The only change you should need to make in **main.cpp** should be to report the **Big O analysis** of the time complexity of each *SelfBalancedBST* operation in the appropriate output messages. 

The image below shows the final expected output for an **AVL Tree** implementation (with Time Complexity hidden):

<img width="600px" src="https://prog2400.netlify.app/ex9-output-AVL.png" alt="EX9 AVL Output">

The image below shows the final expected output for an **Red-Black Tree** implementation (with Time Complexity hidden):

<img width="600px" src="https://prog2400.netlify.app/ex9-output-Red-Black.png" alt="EX9 Red-Black Output">

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


