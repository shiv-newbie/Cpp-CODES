#include<iostream>
#include<stdio.h>
#include<string>

using namespace std;

struct node
{
    int num;
    node* next;
};

void last(node* head, int num)
{
    cout << "----------  ";
    
    for(int i = 0; i < num; i++)
        cout << "-------  ";


    node* myNode = head->next;
    
    cout << "\n| NULL |x|->";
    
    int x = num;
    while(x != 0)
    {
        cout << "| " << myNode->num << " |x|";
        cout << "->";
        myNode = myNode->next;
        x--;
    }
    cout << "NULL\n";
    
    cout << "----------  ";
    for(int i = 0; i < num; i++)
        cout << "-------  ";

    cout << "\n\n";
}

void preDelete(node* head, int idx, int num)
{
    cout << "----------  ";
    
    for(int i = 0; i < num; i++)
    {
        if(idx == i)
            cout << "  -------  ";
        else if(idx+1 == i)
            cout << "  -------  ";
        else
            cout << "-------  ";
    }

    node* myNode = head->next;
    
    cout << "\n| NULL |x|->";
    
    int x = num;
    while(x != 0)
    {
        if(num - x == idx)
        {
            cout << "  | " << myNode->num << " |x|";
            cout << "->  ";
        }
        else
        {
            cout << "| " << myNode->num << " |x|";
            cout << "->";
        }
        
        myNode = myNode->next;
        x--;
    }
    cout << "NULL\n";
    
    cout << "----------  ";
    
    for(int i = 0; i < num; i++)
    {
        if(idx == i)
            cout << "  -------  ";
        else if(idx+1 == i)
            cout << "  -------  ";
        else
            cout << "-------  ";
    }


    cout << "\n\n";
}

void preAdd(node* head, int idx, int num)
{
    cout << "=> Seperating the nodes present at that index.\n";
    cout << "----------  ";
    
    for(int i = 0; i < num; i++)
    {
        if(idx == i)
            cout << "  -------  ";
        else
            cout << "-------  ";
    }

    node* myNode = head->next;
    
    cout << "\n| NULL |x|->";
    
    int x = num;
    while(x != 0)
    {
        if(num - x == idx)
        {
            cout << "  | " << myNode->num << " |x|";
            cout << "->";
        }
        else
        {
            cout << "| " << myNode->num << " |x|";
            cout << "->";
        }
        
        myNode = myNode->next;
        x--;
    }
    cout << "NULL\n";
    
    cout << "----------  ";
    
    for(int i = 0; i < num; i++)
    {
        if(idx == i)
            cout << "  -------  ";
        else
            cout << "-------  ";
    }

    cout << "\n\n";
}

int main()
{
    node* head = new node;
    head->num = -1;
    int num = 5, tot = 0;
    string cond;
    
    string readMe = "\n-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-\n\nRead Me\n~~~~~~~\n\n=> Type \"APPEND\" to add a number at the end\n=> Type \"ADD\" to add a number at a particular index\n=> Type \"DELETE\" to delete a number at a particular index\n=> Type \"END\" to EXIT\n=> Type \"HELP\" to see this \"Read Me\" again \n\n-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-\n\n";
    
    cout << readMe;
    while(true)
    {
        cout << "Enter your command: ";
        cin >> cond;
        if(cond == "END")
        {
            //END
            break;
        }

        int idx;
        if(cond == "ADD")
        {
            //ADD
            cout << "Enter the index (0";
            if(tot-1 >= 0)
                cout << "-" << tot;
            cout << "): ";
            cin >> idx;
            
            if(idx > tot)
            {
                cout << "Index out of range\n";
                continue;
            }
            
            cout << "Enter the number: ";
            cin >> num;

            cout << "\n=> Linked List before adding " << num << ".\n";
            last(head, tot);
            
            node* here = new node;
            here->num = num;
            
            node* myNode = head;
            for(int i = 0; i < idx; i++)
                myNode = myNode->next;

            
            node* x = myNode->next;
            myNode->next = here;
            here->next = x;
            
            tot++;
            cout << "=> Adding the " << num << " at the index.\n";
            preDelete(head, idx, tot);
            
            cout << "=> Linked List after adding " << idx << ".\n";
            last(head, tot);
        
        }
        else if(cond == "DELETE")
        {
            //DELETE
            if(tot == 0)
            {
                cout << "The linked list is empty\n\n";
                continue;
            }
            
            cout << "Enter the index (0";
            if(tot-1 != 0)
                cout << "-" << tot-1;
            
            cout << "): ";
            cin >> idx;
            
            cout << "\n=> Linked List before deleting " << idx << ".\n";
            last(head, tot);
            
            if(idx > tot-1 || idx < 0)
            {
                cout << "Index not in range.\n";
            }
            else
            {
                cout << "=> Seperating the node at the index.\n";
                preDelete(head, idx, tot);
                node* myNode = head;
                
                for(int i = 0; i < idx; i++)
                    myNode = myNode->next;
                
                myNode->next = myNode->next->next;
                tot--;
                cout << "=> After linking the node before and after the index " << idx << ".\n";
                last(head, tot);
            }
        }
        else if(cond == "APPEND")
        {
            //APPEND
            cout << "Enter the number (0-9): ";
            cin >> idx;
            node* myNode = head;
            
            cout << "\n=> Linked List before adding " << idx << ".\n";
            last(head, tot);
            
            for(int i = 0; i < tot; i++)
                myNode = myNode->next;
            
            myNode->next = new node;
            myNode = myNode->next;
            myNode->num = idx;
            
            tot++;
            
            cout << "=> Linked List after adding " << idx << ".\n";
            last(head, tot);
        }
        else if(cond == "HELP")
        {
            // HELP
            cout << readMe;
        }
        else if(cond == "END")
        {
            //END
            break;
        }
        else
        {
            //ANYTHING ELSE
            cout << "Please enter one of these commands: APPEND, ADD, DELETE, END, HELP\n";
        }
    }
    
    cout << "\n======================\n!!  HAPPY LEARNING  !!\n======================\n\n";
}
