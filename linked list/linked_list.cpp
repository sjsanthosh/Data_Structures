#include<iostream>
#include<stack>
using namespace  std;


//the node

class node {
private:
	int data;					// to store data
	node* next;					//to save next pointer
public:
	node(int a, node* ptr){		// constructor with two args	
		data = a;
		next = ptr;
	}

	node(){						//default constructor
	
		data = 0;
		next = NULL;
	
	}
	node(int a){				//single argument constructor
		data = a;
		next = NULL;

	}

	void print(){				// to print the node
		cout << data << " -> ";
		if (next == NULL)
			cout << "\b\b\b";

	}

	node* next_item(){			// to get next node
		return next;
	}

	int curr_data(){			// to get data of node
		return data;
	}

	void set_nxt_item(node* ptr){	// to set next pointer 	
		next = ptr;
	}

	void set_curr_data(int a){		//set the data of current node
		data = a;
	}

};


// the list

class list{
private:
	node* head;
	node* tail;

public:
	list():head(),tail(){};				//constructor
	
	
	node* get_head(){ return head; }
	node** get_head_ptr(){ return &head; }
	void  print(){					// to print the list 
		node * ptr;
		ptr = head;
		if (ptr == NULL)
			cout << "empty list";
		else
		while (ptr != NULL)
		{
			if (ptr == NULL)
				cout << "empty list";
			else
				ptr->print();
			ptr = ptr->next_item();

		};


	}

	void insert(int a){						// to insert in to list
		if (head == NULL)
		{
			node* ptr = new node(a);
			head = ptr;
			tail = head;
		}
		
		else if (tail==head)
		{
			node* ptr = new node(a);
			head->set_nxt_item(ptr);
			tail = ptr;
		}
		else 
		{
			node* ptr = new node(a);
			tail->set_nxt_item(ptr);
			tail = ptr;
		}


	}
  
	void del(int a){					// delete an element from list
		node* ptr = head;
		node* prev;
	if (ptr!=NULL&& ptr->curr_data()==a)
		{
			head = ptr->next_item();
			delete(ptr);
			return;
		}
		else
		{ 

			prev = head;
			ptr = head->next_item();
			while (ptr!=NULL)
			{
				if (ptr->curr_data() == a)
				{
					prev->set_nxt_item(ptr->next_item());
					delete(ptr);
					return;
				}
				else{
					prev = ptr;
					ptr = ptr->next_item();
				}
			}

			cout << "element "<<a<<" not found in the list\n";
		}

	}

	node* search(int a){
		node* ptr = head;
		while (ptr!=NULL)
		{
			if (ptr->curr_data() == a){
				return ptr;
			}
			else
			{
				ptr = ptr->next_item();
			}
		}
		cout << "::::element not found::::\n";
	}

	void del_single(node* ptr){					//delete a node if its pointer is given
	
		node* tmp;

		if (ptr->next_item() != NULL)
		{
			tmp = ptr->next_item();
			ptr->set_curr_data(tmp->curr_data());
			ptr->set_nxt_item(tmp->next_item());
			delete(tmp);
		}
		else
		{
			delete(ptr);
		}
	
	
	}

	node** nth_node(int n){				// nth node of a list :returns a pointer to nth node 
		
		
			node* ptr=head ;
			int i = 1;

			if (n>length())
			{
				cout << "\n:::::out of bounds::::::\n";
				return NULL;
			}


			while (ptr!=NULL&&i<n )
			{
				ptr = ptr->next_item();
				i++;
			
			}

			if (ptr != NULL&&i==n){
				cout << "\nthe " << n << "th node is ";
				//ptr->print();
				cout << "\b\b\b";
				return &ptr;
			}

	}

	int length(){					//to find the length of the list
	
		node * ptr = head;
		int s=1;
		if (ptr==NULL)
		{
			return 0;
		}
		else
		{
			while (ptr->next_item()!= NULL)
			{
				s++;
				ptr = ptr->next_item();
			}
			return s;
		}
	
	}

	node** mid_node(){
	if (length()%2==0)
		return	nth_node(length() / 2);
	else
		return	nth_node((length() / 2)+1);


	}

	node** nth_frm_end(int n){
		return nth_node(length() - (n-1));
	}

	void del_list(node* ptr){
		if (ptr->next_item() == NULL)
		{
			delete(ptr);
		}
		else
		{
			del_list(ptr->next_item());
		}

	}

	

	int count_rep(int a){
		node* ptr = head;
		int i = 0;
		while (ptr!=NULL)
		{
			if (ptr->curr_data()==a)
			{
				i++;
			}
			ptr = ptr->next_item();
		}
		return i;
	}

	bool detect_loop(){
	
		node* slow=head;
		node* fast=head->next_item();

		while (slow && fast &&fast->next_item())
		{
			if (slow == fast)
				return true;

			slow = slow->next_item();
			fast = fast->next_item()->next_item();
		}
		return false;
	
	}
	
	
	void recursiveReverse(node** head_ref)
	{
		struct node* first;
		struct node* rest;

		/* empty list */
		if (*head_ref == NULL)
			return;

		/* suppose first = {1, 2, 3}, rest = {2, 3} */
		first = *head_ref;
		rest = first->next_item();

		/* List has only one node */
		if (rest == NULL)
			return;

		/* reverse the rest list and put the first element at the end */
		recursiveReverse(&rest);
		first->next_item()->set_nxt_item(first);

		/* tricky step -- see the diagram */
		first->set_nxt_item(NULL);

		/* fix the head pointer */
		*head_ref = rest;
	}



   bool	is_palindrome(){
		node* ptr = head;
		stack<int> stk;
		while (ptr!=NULL)
		{
			stk.push(ptr->curr_data());
			ptr=ptr->next_item();

		}

		
		ptr = head;
		while (ptr!=NULL)
		{

			if (ptr->curr_data() == stk.top())
			{
				stk.pop();
				ptr = ptr->next_item();
			}
			else{
			return false;
			}
		}

		
		return true;


	}

   void print_rev(node* ptr){
	  //cout << "1";
	  if (ptr == NULL)
		  return;
		  
		  print_rev(ptr->next_item());
	  
	  
		  cout << ptr->curr_data()<<" ->";
	  
  }


};



int main(int argc, char* argv[]){
	

	list* lst;
	lst=new list();
	lst->insert(10);
	lst->insert(20); 
	lst->insert(30);
	lst->insert(40);
	lst->insert(30);
	lst->insert(60);
	lst->insert(70);
	lst->del(20000);
	cout << lst->length()<<" nodes \n";
	lst->print();
	
	lst->nth_node(1);
	lst->nth_node(2);
	lst->nth_node(3);
	lst->nth_node(4);
	lst->nth_node(5);
	lst->nth_node(6);
	lst->nth_node(7);
	lst->nth_frm_end(2);
	lst->mid_node();
	
	lst->print();
	cout<<"\n"<<lst->count_rep(60)<<endl;
	//node* head = lst->get_head();

	lst->recursiveReverse(lst->get_head_ptr());
	cout << lst->detect_loop();
	lst->print();
	node** mid = lst->mid_node();
//	lst->recursiveReverse(mid);
	cout << "\nfinal list:";
	lst->print();
	cout << "\n checking is list a palindrome :" << lst->is_palindrome();
	cout << endl;
	cout << "\nfinal list:";
	lst->print();
	cout << endl<<"reverse print:";
	lst->print_rev(lst->get_head());



}

