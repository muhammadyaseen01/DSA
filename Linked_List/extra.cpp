void display()
{
    Node *curr = new Node(); // memory allocation     //Node* curr = head2 ------> aisy bhi kr sakte direct
    curr = head2;             // inintialize a current pointer which traverse and print dones value one by one

    // Node* curr =head2;
    cout << "\n List is: ";
    while (curr != NULL)
    {                                   // jab curr NULL hojaye to break hojayega loop(curr null to agy list khatam --->print k liye value hi nh bachegi)
        cout << curr->val << " --> ";   // new_val ko me uper val me store kr chuka hun to ab val me value h to ussi ko print krnga
        cout << curr->next << " ---> "; // print address of next node
        curr = curr->next;              // curr ko move krne k liye curr k next ko curr me store
    }
    cout << "NULL" << endl; // jab list khatam to NULL print
    cout << endl;
}