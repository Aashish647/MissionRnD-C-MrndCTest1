/*
Given two SORTED Circular Linked Lists ,
Write a function to merge those two linked lists .
The First Linked List head should point to the final merged linked list .
The Final merged linked list should also be in SORTED order and a Circular Linked List.
You need to return the Length of Final SLL.

*********
The First linked list head should now point to the Final sorted(Ascending) Linked list First Node
*********
Ex : A: 0->3->5->10->20 (and 20 now pointing back to 0,instead of Null )
B: 1->2->6->11->21->50->70 (70 Pointing back to 1).

The Final Linked List is A:0->1->2->3->5->6->10->11->20->21->50->70 .

Note : Dont use Malloc or create any new nodes ,Only pointers need to be interchanged,
You can use temp pointers although.
Note : The Final Linked List should be  also be a circular Linked List where Last node is
pointing towards the first node.
Note : Return -1 for Invalid Inputs like NULL;

Input : head1 and head2 are Addresses of Two Circular Linked Lists heads .
Output :Return Length of New SLL .Modify the head1 value, such that it now points to 
Merged Sorted Circular SLL .

Difficulty : Medium
*/
#include <stdlib.h>
#include <stdio.h>

struct node{
	int data;
	struct node *next;
};
int merge_circularlists(struct node **head1, struct node **head2){
	//Returns Length of merged Sorted circular SLL and also points *head1 to final SLL .
	//return -1;
	if (((*head1) == NULL) || ((*head2) == NULL)){
		return -1;
	}
	
	int length1 = 0, length2 = 0, limit1 = (*head1)->data, limit2 = (*head2)->data, stop_flag = 0, final_length = 0;
	struct node *final_list, *temp1 = *head1, *temp2 = *head2, *curr_node;
	
	

	while ((*head1 != NULL) || (((*head1)->next)->data != limit1)){
		length1 += 1;
	}
	while ((*head2 != NULL) || (((*head2)->next)->data != limit2)){
		length2 += 1;
	}


	if (limit1 <= limit2){
		final_list = *head1;
		*head1 = (*head1)->next;
	}
	else{
		final_list = *head2;
		*head2 = (*head2)->next;
	}
	curr_node = final_list;

	while (1){
		if (((((*head1)->data) == limit1) || (((*head2)->data) == limit2)) && stop_flag == 1){
			break;
		}

		if (((*head1)->data) <= ((*head2)->data)){

			curr_node->next = *head1;
			(*head1) = (*head1)->next;
		}
		else{

			curr_node->next = *head2;
			(*head2) = (*head2)->next;
		}
		stop_flag = 1;
	
	}

	while (((*head1)->data) != limit1){

		curr_node->next = *head1;
		(*head1) = (*head1)->next;
	}
	while (((*head2)->data) != limit2){

		curr_node->next = *head2;
		(*head2) = (*head2)->next;
	}
	curr_node->next = final_list;
	curr_node = curr_node->next;
	(*head1) = curr_node;
	stop_flag = 0;
	while (1){
		if ((((*head1)->data) == (final_list->data)) && (stop_flag == 1)){
			break;
		}
		final_length += 1;
		final_list = final_list->next;
		stop_flag = 1;
	}
	return final_length;
}