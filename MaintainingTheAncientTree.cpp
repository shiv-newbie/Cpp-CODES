/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 158980
 * Submitted at:  2021-04-22 07:14:02
 *
 * User ID:       1145
 * Username:      56041529
 * Problem ID:    820
 * Problem Name:  Maintaining the Ancient Tree
 */

#include <iostream>
#include <vector>
#include <map>

using namespace std;


// each node will keep the account of the number of sub-branches of, if it is to be cut, if it is already cut, if it is already initialised
struct node
{
    vector<node*> child;
    bool to_cut = true;
    bool is_cut = false;                    // for calculation of cuts;
    map<int, int> indexing;
    int wow[101] = {0};
};


// Counting the cuts
int count_cuts(node* calculate)
{
    int count = 0;
    if(calculate->to_cut)
    {
        if(calculate->is_cut)
            return 0;
        calculate->is_cut = true;
        return 1;
    }
    else
    {
        for(int i = 0; i < calculate->indexing.size(); i++)
        {
            count += count_cuts(calculate->child[i]);
        }
    }
    return count;
}

int main()
{
    int cases;
    cin >> cases;
                         // To check if this node is aleady made before
    while(cases--)                              // How many cases we are facing
    {
        int n, m;
        cin >> n >> m;
        node* myNode = new node;
        map<int, int> indexing;
        int wow[100] = {0};
        while(n--)                              // n -> number of input cases for removing
        {
            node* track = myNode;                // To create an instance of the actual tree so that we know the root node->myNode
            int details;
            cin >> details;
            if(wow[details] == 0)
            {
                wow[details] = 1;
                track->indexing.insert(pair<int,int>(details,track->indexing.size()));              // To keep track of where we have inserted the node in the main branch
                node* myNew = new node;
                track->child.push_back(myNew);
            }
            track = track->child[track->indexing.find(details)->second];
            
            cin >> details;                     // taking in the sub-node [if present] to cut
            while(details != -1)
            {
                
                if(track == NULL)
                {
                    track = new node;
                }
                if(track->wow[details] == 0)
                {
                    track->wow[details] = 1;
                    track->indexing.insert(pair<int,int>(details,track->indexing.size()));          // To keep track of where we have inserted the sub-node in the node
                    node* myNew = new node;
                    track->child.push_back(myNew);
                }
                track = track->child[track->indexing.find(details)->second];
                cin >> details;
            }
        }
        while(m--)
        {
            
            node* track = myNode;                // To create an instance of the actual tree so that we know the root node->myNode
            int details;
            cin >> details;
            if(wow[details] == 0)
            {
                cin >> details;
                while(details != -1)
                    cin >> details;
                continue;
            }
            track = track->child[track->indexing.find(details)->second];
            track->to_cut = false;
            
            cin >> details;                     // taking in the sub-node [if present] to cut
            while(details != -1)
            {
                if(track == NULL || track->wow[details] == 0)
                {
                    cin >> details;
                    while(details != -1)
                        cin >> details;
                    continue;
                }
                track = track->child[track->indexing.find(details)->second];
                track->to_cut = false;
                cin >> details;
            }
        }
        
        // Counting of the cuts to be made
        int count = 0;
        for(int i = 0; i < myNode->indexing.size(); i++)
        {
            if(myNode->child[i]->indexing.size() == 0)
                count += 1;
            else
                count += count_cuts(myNode->child[i]);
        }
        cout << count << endl;
    }
}
