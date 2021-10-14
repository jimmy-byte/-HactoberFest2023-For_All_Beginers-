#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class treenode
{
public:
    int val;
    treenode *left;
    treenode *right;
};

class stacknode
{
public:
    treenode *addr;
    stacknode *next;
};

class mystack
{
private:
    stacknode *top;
public:
    mystack()
    {
        top = NULL;
    }
    void push(treenode *addr);
    treenode *pop();
    int is_stack_empty();
};

void mystack::push(treenode *addr)
{
    if(top == NULL)
    {
        top = new stacknode();
        top->addr = addr;
        top->next = NULL;
    }
    else
    {
        stacknode *temp = new stacknode();
        temp->addr = addr;
        temp->next = top;
        top = temp;
    }
}

treenode *mystack::pop()
{
    if(top == NULL)
        return NULL;
    else
    {
        stacknode *temp = top;
        top = top -> next;
        return temp->addr;
    }
}

int mystack::is_stack_empty()
{
    if(top==NULL)
        return 1;
    else
        return 0;
}


class BST
{
public:
    treenode *root;

    BST()
    {
        root = NULL;
    }
    void create_bst();
    void insert_node_in_bst(treenode *temp);
    void recursive_inorder_traversal(treenode *temp);
    void recursive_preorder_traversal(treenode *temp);
    void recursive_postorder_traversal(treenode *temp);
    void non_recursive_inorder_traversal();
    void non_recursive_preorder_traversal();
    void non_recursive_postorder_traversal();
    void delete_node_from_bst();
};

void BST::delete_node_from_bst()
{
    treenode *c, *p;
    int no;
    p = NULL;
    c = root;

    cout<<"Enter the node to be deleted: ";
    cin>>no;

    while(1)
    {
        if(c == NULL)
            break;
        else if(c->val == no)
            break;
        else if(c->val > no)
        {
            p = c;
            c = c->left;
        }
        else
        {
            p = c;
            c = c->right;
        }

    }
    if(c==NULL)
    {
        cout<<"\n Node is not present in the tree";
    }
    else if(c == root)
    {
        //case 1 : leaf node
        if(c->left == NULL && c->right == NULL)
        {
            root = NULL;
            delete c;
        }
        else if(c->left != NULL && c->right == NULL)
        {
            root = c->left;
            delete c;
        }
        else if(c->left == NULL && c->right != NULL)
        {
            root = c->right;
            delete c;
        }
        else
        {
            treenode *p1, *c1;
            p1 = c;
            c1 = c->left;
            while(c1->right != NULL)
            {
                p1 = c1;
                c1 = c1->right;
            }
            // copy value of c1 to c
            if(p1==c)
            {
                p1->left = c1->left;
                delete c1;
            }
            else
            {
                c->val = c1->val;
                if(c1->left == NULL && c1->right == NULL)
                    delete c1;
                else if(c1->left != NULL && c1->right == NULL)
                {
                    p1->left = c1->left;
                    delete c1;
                }
                else
                {
                    p1->right = c1->left;
                    delete c1;
                }
            }
        }
    }
    else
    {
        //case 1 : leaf node
        if(c->left == NULL && c->right == NULL)
        {
            if(p->left == c)
            {
                p->left = NULL;
                delete c;
            }
            else
            {
                p->right = NULL;
                delete c;
            }
        }
        //case 2 only left subtree
        else if(c->left != NULL && c->right == NULL)
        {
            //if node to be deleted is connected to the left of parent
            if(p->left == c)
            {
                p->left = c->left;
                delete c;
            }
            // if node to be deleted is connected to the right of parent
            else
            {
                p->right = c->left;
                delete c;
            }
        }
        //case 3 only right subtree
        else if(c->left == NULL && c->right != NULL)
        {
            //if node to be deleted is connected to the left of parent
            if(p->left == c)
            {
                p->left = c->right;
                delete c;
            }
            // if node to be deleted is connected to the right of parent
            else
            {
                p->right = c->right;
                delete c;
            }
        }
        //case 4 : Node to be deleted has both left and right subtree.
        else
        {
            // first find inorder predecessor of node to be deleted i.e. c in our case
            // inoder predecessor of a node is
            // node with maximum value in the left subtree of the node
            treenode *p1, *c1;
            p1 = c;
            c1 = c->left;
            while(c1->right != NULL)
            {
                p1 = c1;
                c1 = c1->right;
            }

            // copy value of c1 to c
            c->val = c1->val;
            if(p1==c)
            {
                p1->left = c1->left;
                delete c1;
            }
            else
            {
                if(c1->left == NULL && c1->right == NULL)
                {
                    p1->right = NULL;
                    delete c1;
                }

                else
                {
                    p1->right = c1->left;
                    delete c1;
                }
            }
        }
        cout<<"\n Node with value "<<no<<" has been deleted";
    }
}
void BST::create_bst()
{
    int no;
    int choice;
    treenode *temp;
    while(1)
    {
        cout<<"Enter the value : ";
        cin>>no;
        temp = new treenode();
        temp->val = no;
        temp->left = NULL;
        temp->right = NULL;
        insert_node_in_bst(temp);
        cout<<"\nDo you want to continue? (1/0) :";
        cin>>choice;
        if(choice == 0)
            break;
    }
}

void BST::insert_node_in_bst(treenode *temp)
{


    if(root == NULL)
    {
        root = temp;
    }

    else
    {

        treenode *temp1 = root;
        while(1)
        {
            if(temp1->val > temp->val)
            {
                if(temp1->left ==NULL)
                {
                    temp1->left = temp;
                    break;
                }
                else
                {
                    temp1 = temp1->left;
                }
            }
            else
            {
                if(temp1->right ==NULL)
                {
                    temp1->right = temp;
                    break;
                }
                else
                {
                    temp1 = temp1->right;
                }
            }
        }
    }
}

void BST::recursive_inorder_traversal(treenode *temp)
{
    if(temp->left != NULL)
        recursive_inorder_traversal(temp->left);
    cout<<"\t "<<temp->val;
    if(temp->right != NULL)
        recursive_inorder_traversal(temp->right);
}

void BST::recursive_preorder_traversal(treenode *temp)
{
    cout<<"\t "<<temp->val;
    if(temp->left != NULL)
        recursive_preorder_traversal(temp->left);
    if(temp->right != NULL)
        recursive_preorder_traversal(temp->right);
}

void BST::recursive_postorder_traversal(treenode *temp)
{
    if(temp->left != NULL)
        recursive_postorder_traversal(temp->left);
    if(temp->right != NULL)
        recursive_postorder_traversal(temp->right);
    cout<<"\t "<<temp->val;
}

void BST::non_recursive_inorder_traversal()
{
    mystack s1;
    treenode *temp = root;

    cout<<endl<<"Non Recursive Inorder Traversal: "<<endl;
    while(1)
    {
        while(temp != NULL)
        {
            s1.push(temp);
            temp = temp->left;
        }

        if(s1.is_stack_empty())
            break;
        temp = s1.pop();
        cout<<"\t "<<temp->val;   //move one node right
        temp = temp->right;
    }
}

void BST::non_recursive_preorder_traversal()
{
    mystack s1;
    treenode *temp = root;

    cout<<endl<<"Non Recursive Preorder Traversal: "<<endl;
    while(1)
    {
        while(temp != NULL)
        {
            cout<<"\t "<<temp->val;
            s1.push(temp);
            temp = temp->left;
        }

        if(s1.is_stack_empty())
            break;
        temp = s1.pop();

        temp = temp->right;
    }
}

void BST::non_recursive_postorder_traversal()
{
    mystack s1;
    mystack s2;
    treenode *temp = root;
    //push non-recursive postorder
    s1.push(root);
    cout<<endl<<"Non Recursive Postorder Traversal: "<<endl;
    while(1)
    {
        if(s1.is_stack_empty())
            break;
        temp = s1.pop();
        s2.push(temp);
        if(temp->left != NULL)
            s1.push(temp->left);
        if(temp->right != NULL)
            s1.push(temp->right);
    }

    while(1)
    {
        if(s2.is_stack_empty())
            break;
        temp = s2.pop();
        cout<<"\t "<<temp->val;
    }
}

int main()
{
    BST b;
    treenode *temp;
    int ch;
    cout<<"<----------Welcome to BST Tree---------->";
    while(ch!=5)
    {
    	cout<<"\n\n1.Create BST\n2.Recursive Traversal\n3.Non Recursive Traversal\n4.Delete Node BST\n5.Exit\n";
    	cout<<"\n\nEnter your choice:-\n";
    	cin>>ch;
    	switch(ch)
    {
    	case 1:
    		b.create_bst();
    		temp = b.root;
    		break;
    		
    	case 2:
    		int ch1;
    		cout<<"Select Recursive Traversal:-\n1.Inorder\n2.Preorder\n3.Postorder\n";
    		cin>>ch1;
    		if(ch1==1)
    		{
    			cout<<endl<<"Recursive Inorder Traversal:"<<endl;
   				b.recursive_inorder_traversal(temp);	
			}
   			if(ch1==2)
   			{
   				cout<<endl<<"Recursive Preorder Traversal:"<<endl;
                b.recursive_preorder_traversal(temp);	
			}
            if(ch1==3)
            {
            	cout<<endl<<"Recursive Postorder Traversal:"<<endl;
    	        b.recursive_postorder_traversal(temp);	
			}
				    
    	    break; 
			  
    	case 3:
    		int ch2;
			cout<<"Select Non-Recursive Traversal:-\n1.Inorder\n2.Preorder\n3.Postorder\n";
			cin>>ch2;
			if(ch2==1)
			{
				b.non_recursive_inorder_traversal();
			}
				
			if(ch2==2)
			{
				b.non_recursive_preorder_traversal();
			}
				
			if(ch2==3)
			{
				b.non_recursive_postorder_traversal();
			}
			break;
			
		case 4:
			b.delete_node_from_bst();
			cout<<"\n\nBST after deleted value:-\n";
			b.recursive_inorder_traversal(temp);
			break;							
	}
    	
    	
	}
    
return 0;	    
    }
