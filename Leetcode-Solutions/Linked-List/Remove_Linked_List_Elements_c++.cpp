ListNode* removeElements(ListNode* head, int val) {
	if(!head) return head;

	ListNode* node = head;
	while(node && node -> next)
	{
		if(node -> next -> val == val)
			node -> next = node -> next -> next;
		else
			node = node -> next;
	}

	if(head -> val == val)
		head = head -> next;

	return head;
}
