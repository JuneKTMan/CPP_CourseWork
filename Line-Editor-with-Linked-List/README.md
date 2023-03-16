<img width="150px" src="https://www.nscc.ca/img/aboutnscc/visual-identity-guidelines/artwork/nscc-jpeg.jpg" >

# PROG 2400 - Assignment 1 - Line Editor


## Task

Write a simple line editor. Keep the entire text in a **linked list**, with each single line in a separate node at a position reflected by its line number. 

 - Start the program by entering **EDIT [file]**
 - The program will then wait for a command to be entered, starting with a colon (":")
 - If the command **:I** is entered, a prompt appears along with the current line number and the program will be in **insert mode**. If the command **:I** is entered with a number **n** following it, then insert the text to be followed at line **n**. If **:I** is not followed by a number, then insert the text before the first line. 
 - If **:D** is entered with two numbers **n** and **m**, one **n**, or no number following it, then delete lines **n** through **m**, line **n**, or the current line. 
 - Command **:L** stands for listing lines. It can be entered with two numbers **n** and **m**, one **n**, or no number following it, then list lines **n** through **m**, only line **n**, or all the lines. 
 - The command **:E** signifies exit and saving the text in a file.

**NOTE: You should have a destructor on your LinkedList class that goes through the list and deletes all of the Nodes.**

## Example Images:

*Starting program, selecting file, inserting some text, listing current lines:*

<img width="600px" src="https://prog2400.netlify.app/assign1-output1.png" alt="Assign1 Output 1">

*Inserting some text at line number, listing some lines, deleting some lines:*

<img width="600px" src="https://prog2400.netlify.app/assign1-output2.png" alt="Assign1 Output 2">

*Inserting some text at line number, deleting one line:*

<img width="600px" src="https://prog2400.netlify.app/assign1-output3.png" alt="Assign1 Output 3">

*Listing all lines, exiting and saving the file:*

<img width="600px" src="https://prog2400.netlify.app/assign1-output4.png" alt="Assign1 Output 4">

*Sample file contents:*

<img width="600px" src="https://prog2400.netlify.app/assign1-file-contents.png" alt="Assign1 File Contents">

## Submission Instructions
### Video Recording Submission:

You will demonstrate the completion of this project via a **video screen-capture recording** of you using CLion, GitBash, and viewing your code to show completion of the **Video Submission Checklist**, which is posted on Brightspace. You will post **either your video file or a link to it** (e.g. a Microsoft Stream recording, make sure to give the instructor permissions to watch it), to the Brightspace Assignment 1 Dropbox prior to the deadline. If you are not sure of how best to capture such a video, seek advice from the instructor prior to the deadline.

NOTE: MAKE SURE TO SHOW EVERYTHING IN THE VIDEO SUBMISSION CHECKLIST STEP-BY-STEP. YOU WILL NEED AUDIO IN THE VIDEO FOR AT LEAST THE CODE REVIEW PORTION OF THE CHECKLIST

> Written with [StackEdit](https://stackedit.io/).
