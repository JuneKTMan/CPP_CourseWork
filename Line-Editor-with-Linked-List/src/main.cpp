#include <iostream>
#include <fstream>
#include <list>
#include <sstream>


#include "../inc/linked_list.hpp"

using namespace std;

LinkedList myLinkedList;
Node *deletedNode;
string command_start_end[3];

string command;
int newIndex;




/////////////////////GET COMMAND ////////////////////////

// Get the user input comand and number
void getCommandNum(string &command , int &start_num, int &end_num){

    string input;
    getline(cin, input);

    istringstream getall(input);

    getall >> command >> start_num >> end_num;

}

string getMode(string command) {
    return command;
}

int getNumber(string command, int start_num, int end_num) {
    if (end_num == 0) {
        return start_num;
    }else if (end_num != 0){
        return end_num;
    }else{return 0;}

}




///////////MAIN//////////

int main() {


        // YOU CODE SHOULD GO HERE
        // BE AWARE THE MAKEFILE IS ALSO EXPECTING A SECOND CPP FILE FOR THE LINKED_LIST

        string command;
        string option;
        string line;
        Node* head = nullptr;
        string editfilename[2];


        cout << "Must type EDIT [file] to start!!" << endl;
        //Get the second input after space in a single line
        cin >> editfilename[0] >> editfilename[1];
        //print the file name first
        cout << "Editing Output file: " << editfilename[1] << endl;


        // run the program
        if (!editfilename[1].empty()) {

            do {
                int start_num = 0;
                int end_num = 0;

                cout << "Waiting for command (:I/:D/:L/:E) >";
                // This part is use to get the user input value (string) (num) (num)
                getCommandNum(command, start_num, end_num);

                // This part is use to get the user input mode , start num and end num
                if (start_num == 0 && end_num == 0) {
                    getMode(command);
                } else if (end_num == 0) {
                    getNumber(command, start_num, end_num);
                } else {
                    getNumber(command, start_num, end_num);
                }
                // Top level of selection : L / :I / :D / :E

                if (getMode(command) == ":L") {
                    //LIST MODE UI
                    cout << "LIST mode" << endl;

                    if (start_num == 0 && end_num == 0) {
                        // This is the List at the beginner
                        cout << "List form beginning" << endl;
                        //reverse the linklist
                        myLinkedList.reverse();
                        myLinkedList.print();


                    } else if (end_num == 0) {
                        // This is insert by List at location
                        cout << "List at location" << endl;
                        if (start_num == 1) {
                            myLinkedList.reverse();
                            myLinkedList.print();
                            getCommandNum(command,start_num,end_num);

                        }

                        if (start_num != 1) {
                            start_num = newIndex;
                            myLinkedList.printIndexList(newIndex, start_num);
                            getCommandNum(command,start_num,end_num);
                        }

                    } else if (start_num != 0 && end_num != 0) {
                        // This is with range mode start to end, run for loop
                        cout << "List in range" << endl;
                        for(newIndex = start_num; newIndex < end_num + 1 ; newIndex ++) {
                            cout << newIndex << ">";
                            myLinkedList.print();

                        }
                        getCommandNum(command,start_num,end_num);

                    }


                    //INSERT MODE UI
                } else if (getMode(command) == ":I") {
                    //INSERT MODE UI


                    if (line[0] != ':I') {
                        cout << "INSERT mode" << endl;
                        if (start_num == 0 && end_num == 0) {
                            // This is the insert at the beginner
                            cout << "insert form beginning" << endl;
                            //Start insert

                            newIndex = 1;
                            do {
                                // index auto ++ when user input press enter, press command : L = out


                                cout << newIndex << ">";
                                newIndex++;
                                cin >> line;
                                if(!line.empty() || line[0] != ':') {
                                    myLinkedList.insertAtBeginning(line);
                                }

                            } while (line[0] != ':');//
                            getCommandNum(command,start_num,end_num);


                        } else if (end_num == 0) {

                            cout << "insert At Location" << endl;

                            getNumber(command, start_num, end_num);



                            if (start_num == 1) {

                                myLinkedList.deleteAtBeginning();
                                cin >> line;
                                myLinkedList.insertAtLocation(start_num, line);
                                getCommandNum(command,start_num,end_num);


                            }
                            if (start_num != 1) {
                                cin >> line;
                                myLinkedList.deleteAtLocation(start_num);
                                myLinkedList.insertAtLocation(start_num, line);
                                getCommandNum(command,start_num,end_num);
                            }


                        } else if (start_num != 0 && end_num != 0) {
                            // This is with start and end, run for loop
                            cout << "Insert in range" << endl;

                            for(newIndex = start_num; newIndex < end_num + 1 ; newIndex ++) {
                                cout << newIndex << ">";
                                cin >> line;
                                myLinkedList.insertAtLocation(newIndex,line);

                            }
                            getCommandNum(command,start_num,end_num);


                        } else {
                            cout << "Can get the start number and the end number" << endl;
                        }
                    } else {

                    }


                } else if (getMode(command) == ":D") {
                    //DELETE MODE UI

                    cout << "DELETE mode" << endl;

                    if (start_num == 0 && end_num == 0) {
                        // This is the List at the beginner
                        cout << "Del from beginning" << endl;
                        myLinkedList.deleteAtBeginning();

                    } else if (end_num == 0) {
                        // This is insert by List at location
                        cout << "Del at location" << endl;
                        if (start_num == 1) {

                            myLinkedList.deleteAtBeginning();

                        }
                        if (start_num != 1) {
                            myLinkedList.deleteAtLocation(start_num);

                        }

                        getCommandNum(command,start_num,end_num);
                    } else if (start_num != 0 && end_num != 0) {
                        // This is with range mode start to end, run for loop
                        cout << "Del in range" << endl;
                        for(newIndex = start_num; newIndex < end_num + 1 ; newIndex ++) {

                            myLinkedList.deleteAtLocation(start_num);

                        }


                    }

                } else if (getMode(command) == ":E") {
                    //EXIT MODE
                    cout << "EXIT mode - writing to " <<editfilename[1]<< endl;

                    if (start_num == 0 && end_num == 0) {
                        // This is the List at the beginner
                        cout << "Save mode" << endl;
                        myLinkedList.print();
                        myLinkedList.saveToFile2(editfilename[1]);

                    } else if (end_num == 0) {
                        // This is insert by List at location
                        cout << "Save mode 2" << endl;

                    } else if (start_num != 0 && end_num != 0) {
                        // This is with range mode start to end, run for loop
                        cout << "Save mode 3" << endl;
                    }

                } else {

                    continue;
                }

            }
            while (getMode(command) != ":E");

        }

        return 0;
    }



