#include<iostream>
#include<string>
#include<cstring>

using namespace std;

struct Node{
    int value;
    Node *left;
    Node *right;
};

class BST{
    private:
        int count;
        Node *root;
        Node *create(int value){
            Node *newnode;
            try{
                newnode = new Node;
            }
            catch (bad_alloc){
                newnode = NULL;
                cerr << "Failed to create node\n";
            }

            newnode->value = value;
            newnode->left = NULL;
            newnode->right = NULL;
            count++;

            return newnode;
        }
        Node *find_node(Node *subtreeroot, int value){
            if(subtreeroot == NULL)
                return NULL;
            if(subtreeroot->value == value)
                return subtreeroot;
            
            Node *found = find_node(subtreeroot->left, value);
            if(found != NULL)
                return found;
            
            return find_node(subtreeroot->right, value);

        }
        void add_node(Node *subtreeroot, int value){
            if(subtreeroot->value != value){
                if(value < subtreeroot->value)
                    if(subtreeroot->left != NULL)
                        add_node(subtreeroot->left, value);
                    else
                        subtreeroot->left = create(value);

                else{
                    if(subtreeroot->right != NULL)
                        add_node(subtreeroot->right,value);
                    else 
                        subtreeroot->right = create(value);
                }
            }
            

        }
    public:
        BST(){
            root = NULL;
            count = 0;
        }
        void add(int item){
            if(root == NULL)
                root = create(item);
            else
                add_node(root, item);
            
        }
        void show_node(Node *subtreeroot){
            if(subtreeroot == NULL)
                return;
            show_node(subtreeroot->left);
            cout << subtreeroot->value << "\n";
            show_node(subtreeroot->right);
            

        }
        void destroy_node(Node *node){
            if( node != NULL){
                destroy_node(node->left);
                destroy_node(node->right);
            }
            delete node;
            count--;
        }
        bool find(int value){
            bool result = false;
            Node *found = find_node(root, value);
            if(found != NULL)
                result = true;

            return result;
        }
        bool delete_node(int value){
            bool found = false;
            Node *temp = root;
            Node *parent = NULL;

            while(!found && temp != NULL){
                if(value == temp->value)
                    found = true;
                else if(value < temp->value){
                    parent = temp;
                    temp = temp->left;
                }
                else if(value > temp->value){
                    parent = temp;
                    temp = temp->right;
                }
            }


                if(temp->right == NULL && temp->left == NULL){
                    if(parent->left == temp)
                        parent->left = NULL;
                    else
                        parent->right = NULL;

                    delete temp;
                    
                }
                else if(temp->left == NULL){
                    Node *child = temp->right;
                    parent->right = child;

                    delete temp;
                }
                else if(temp->right == NULL){
                    Node *child = temp->left;
                    parent->left = child;

                    delete temp;

                }

            if(found){
                    if(temp->left != NULL and temp->right != NULL){
                        Node *replacement = temp->right;
                        while(replacement->left != NULL){
                            parent = replacement;
                            replacement = replacement->left;
                        }
                        temp->value = temp->value;
                        temp = replacement;
                    }
                    
                    Node *subtree = temp->right;
                    if(subtree == NULL)
                        subtree = temp->left;
                    else{
                        if (temp->value < parent->value)
                            parent->left = subtree;
                        else
                            parent->right = subtree;
                    }
                

                delete temp;
                return true;             
            }
            else
                return false;
        }
        friend void show(BST &bst);

        ~BST(){
            destroy_node(root);
        }
};
void show(BST &bst){
    bst.show_node(bst.root);
    
}


int main(){
    BST bst;
    int values[25] = {23,117,45,19,7,13,17,40,9,11,93,49,35,8,3,10,22,77,16,6,51,57,55,90,31};
    for(int i = 0; i < 25; i++){
        bst.add(values[i]);
    }
    int userVal;
    cout << "Enter value to search for: \n";
    cin >> userVal;
    if(bst.find(userVal)){
        int action;
            show(bst);
        cout << "1. Delete Node \n2. Do not Delete node\n";
        cin >> action;
        if(action == 1){
            bst.delete_node(userVal);
            cout << "Deletion Successful\nBinary Search Tree: \n";
            show(bst);
        }
        else if(action == 2)
            cout << "Deletion was cancelled\n";
        
    }
    else
        cout << "Value does not exist in Tree\n";
    
        



    return 0;
}