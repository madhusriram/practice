#include <stack>		// wouldn't need this but only for some help
#include <vector>

// adds to the beginning of the list
template <typename T>
void SinglyList<T>::push_front(T v) {
	Node<T> *tmp = Node<T>::createNode(v);

	length++;

	if (list == nullptr)
		last = tmp;

	tmp->next = list;
	list = tmp;
}


// adds to the beginning of the list from a list
template <typename T>
void SinglyList<T>::push_front(std::list<T> v) {
	for (typename std::list<T>::const_iterator it = v.begin(); it != v.end(); it++) {
		Node<T> *tmp = Node<T>::createNode(*it);

		length++;

		if (list == nullptr)
			last = tmp;
		tmp->next = list;
		list = tmp;
	}
}

// adds to the end of a list
template <typename T>
void SinglyList<T>::push_back(T v) {
	Node<T> *tmp = Node<T>::createNode(v);

	length++;

	if (list == nullptr) { 
		list = last = tmp;
		return;
	}

	last->next = tmp;
	last = tmp;
}


// adds to the end of the list a bunch of values
template <typename T>
void SinglyList<T>::push_back(std::list<T> v) {
	for (typename std::list<T>::const_iterator it = v.begin(); it != v.end(); it++) {
		length++;
		Node<T> *tmp = Node<T>::createNode(*it);
		if (list == nullptr) {
			list = last = tmp;
			continue;
		}
		last->next = tmp;
		last = tmp;
	}
}


// for debugging!
template <typename T>
void SinglyList<T>::traverseList() {
	Node<T> *tmp = list;

	while (tmp != nullptr) {
		std::cout << tmp->data << " ";
		tmp = tmp->next;
	}
	std::cout << std::endl;	
}

// merge 2 sorted lists
/*SinglyList<T> *SinglyList<T>::mergeTwoLists(SinglyList<T> &l1, SinglyList<T> &l2) {
	Node<T> *a = l2;
	Node<T> *b = l1;
	Node<T> *anext;
	Node<T> *bnext;
	bool first = false;
	
	// use a as the list to grow on
	// and b as the list to be merged into a
	if (l1->data < l2->data) {
		a = l1;
		b = l2;
		first = true;
	}

	// Build on a
	// 1 2 3
	// 1 3 4
	while (a) {
		anext = a->next;
		bnext = b->next;

	
	}


	a->next = b;

	if (first)
		return l1;
	
	return l2;
}
*/

// sum list1 and list2 and return a new list object
template <typename T>
void SinglyList<T>::sumLists(SinglyList<T>& l, SinglyList<T> &sumList) {
	Node<T> *l2 = l.list;

	if (list == nullptr && l2 != nullptr) {
		sumList = l;
		return;
	}
	else if (l2 == nullptr && list != nullptr) {
		sumList = *this;
		return;
	}
	else if (l2 == nullptr && list == nullptr) {
		return;
	}

	// now try to add
	Node<T> *l1 = list;

	int carry = 0;
	int d1 = 0;
	int d2 = 0;
	bool isEndOfList1 = false;

	while (true) {	
		if (l1 != nullptr) {
			d1 = l1->data;
			l1 = l1->next;
		} else {
			isEndOfList1 = true;
		}

		if (l2 != nullptr) {
			d2 = l2->data;
			l2 = l2->next;
		} else if (isEndOfList1) { // both lists are done, exit!
			break;
		}

		// calculate sum now!
		int sum = d1 + d2 + carry;
		int res = sum % 10;
		int carry = sum / 10;
		// add to list
		sumList.push_back(res);
	}
	// still might have a carry left over at the end, add it!
	if (carry != 0)
		sumList.push_back(carry);
}

// naive method is to have 2 pointers, fast and slow.
// for each traversal of the slow, add it to the stack.
// after hitting the half point move the slow and pop each from the stack and compare!
// this would O(N) and O(N) space
//
// To reduce the space usage - reverse the second half of the list and compare
// again, note this modifies the original list
template <typename T>
bool SinglyList<T>::isPalindrome() {
	if (! list)
		return true;

	// special case, single node is a palindrome
	if (list->next == nullptr)
		return true;

	Node<T> *fast = list->next;
	Node<T> *slow = list;
	Node<T> *prev;

	// get 2 lists
	// O(N) time and O(1) space
	while (fast && fast->next && fast->next->next) {
		slow = slow->next;
		fast = fast->next->next;
	}
	// to tie the reversed nodes to the first half of the list
	if (fast->next) {
		prev = slow->next;
	} else {
		prev = slow;
	}
	// reverse the fast side of the list
	// O(N) time
	prev->next = reverse(prev->next);
	
	// now the list is good to be compared from the start to the middle in the
	// first list and from the middle to the end in the second list
	Node<T> *copy = list;
	Node<T> *second = prev->next;

	// start second from the right node depending on if we've
	// even or odd nodes
	// O(N) time, O(1) space
	while (true) {
		if (copy->data != second->data)
			return false;

		// signals the end of comparison
		if (copy == slow)
			break;

		copy = copy->next;
		second = second->next;
	}
	return true;
}

template <typename T>
void SinglyList<T>::getListElements(std::list<T> &l) {
	Node<T> *tmp = list;

	while (tmp != nullptr) {
		l.push_back(tmp->data);
		tmp = tmp->next;
	}	
}

// return data at the center of the list
// move one pointer by 1 and the other by 2
// tortoise and hare logic
template <typename T>
T SinglyList<T>::middleOfList() {
	Node<T> *fastptr = list;
	Node<T> *slowptr = list;

	if (list == nullptr || list->next == nullptr)
		return T(-1);

	fastptr = fastptr->next;
	
	while (fastptr != nullptr) {
		if (fastptr->next != nullptr)
			fastptr = fastptr->next->next;
		else
			break;
		slowptr = slowptr->next;
	}

	return slowptr->data;
}

// 1 -> 2 -> 3 -> 4 -> 5 -> NULL
// swap every 2 adjacent nodes
// https://leetcode.com/problems/swap-nodes-in-pairs/
template <typename T>
void SinglyList<T>::swapNodes() {
	Node<T> *tmp = list;
	Node<T> *prev = nullptr;
	bool h = true;

	if (tmp == nullptr)
		return;

	while (tmp) {
		Node<T> *savenext = tmp->next;
		if (savenext != nullptr) {
			tmp->next = savenext->next;
			savenext->next = tmp;
			tmp = savenext;
		} else {
			break;
		}

		if (prev != nullptr) {
			prev->next = tmp;
		}

		// adjust the head
		if (h) {
			list = tmp;
			h = false;
		}	
	
		prev = tmp->next;
		tmp = prev->next;

		if (tmp == nullptr) 
			break;
	}
}

// do not use the last pointer
// should be harmless if there is no "n"th node from the end
template <typename T>
void SinglyList<T>::removeNthFromEnd(int n) {
	Node<T> *tmp = list;
	// advance this pointer only after having tmp moved further along the \
	// list after "n" pos
	Node<T> *deletePtr = list;
	Node<T> *prev = nullptr;

	int delta = 0;

	if (list == nullptr)
		return;
	else if (list->next == nullptr && n > 1)
		return;
 
	while (tmp->next != nullptr) {
		tmp = tmp->next;
		
		if (delta < n)
			delta++;
		
		// start moving the deletePtr
		if (delta == n) {
			prev = deletePtr;
			deletePtr = deletePtr->next;
		}
	}
	// if first node
	if (deletePtr == list) {
		Node<T> *next = list->next;
		delete(deletePtr);
		list = next;
	} else {
		// else, just tie nodes
		prev->next = deletePtr->next;
		delete(deletePtr);
	}
}

// Reverse a list
// Without recursion and with 3 pointers
// Save previous node to tie the next nodes new next
// O(n)
template <typename T>
void SinglyList<T>::reverse() {
	Node<T> *prev = nullptr;
	Node<T> *savenext = nullptr;

	while (list != nullptr) {
		savenext = list->next;
		list->next = prev;
		prev = list;
		list = savenext;
	}
	// set to head
	list = prev;
}

// reverse from start till end and return the new head
template <typename T>
Node<T> *SinglyList<T>::reverse(Node<T> *start) {
	if (! start)
		return nullptr;

	Node<T> *prev = nullptr;
	Node<T> *savenext = nullptr;

	while (start) {
		savenext = start->next;
		start->next = prev;
		prev = start;
		start = savenext;
	}

	return prev;	
}

// helper for reverseKGroup()
// reverse from start to end
template <typename T>
Node<T> *SinglyList<T>::reverseKNodes(Node<T> *start, Node<T> *end, Node<T> *oldList) {
	// use saveend to attach to starts next
	Node<T> *saveend = end->next;
	Node<T> *prev = saveend;

	while (start != saveend) {
		Node<T> *savenext = start->next;
		start->next = prev;
		prev = start;
		start = savenext;	
	}
	
	// stitch previous to new head
	if (oldList)
		oldList->next = prev;
	
	return prev;
}

// Reverse K nodes from the head
// Iteratively reverse K elements and stitch them
template <typename T>
void SinglyList<T>::reverseKGroup(int k) {
	Node<T> *tmp = list;
	Node<T> *start = list;
	bool head = true;
	Node<T> *prev = nullptr;

	int i = 1;

	while (tmp != nullptr) {
		
		// time to reverse the k group
		if (i % k == 0) {
			Node<T> *newhead = reverseKNodes(start, tmp, prev); 
			
			// update object's head of the list
			// happens only once
			// newHead needed only for updating the objects' list head
			// stitching of previously reversed list and
			// current list happens in reverseKNodes()
			if (head) {
				list = newhead;
				head = false;
			}
			
			// store end of previously reversed list
			// to connect to the about to be sorted list
			prev = start;
			
			tmp = start;	// tmp moves to next later
			start = start->next;
		}
		
		++i; 
		tmp = tmp->next; 
	}
}

template <typename T>
void SinglyList<T>::reverseMtoN(int m, int n) {
	Node<T> *l = list;
	Node<T> *savenext;
	Node<T> *last_in_reverse = nullptr;
	Node<T> *first_in_reverse;
	Node<T> *prev;
	Node<T> *reverseList = nullptr;
	bool from_first = false;

	int len = n - m + 1;

	if (m == 1)
		from_first = true;	

	// traverse until the m - 1 node is reached
	for (int i = 1; i + 1 < m; i++) {
		l = l->next;
	}

	if (! from_first) {
		prev = l;
		l = l->next;
	}

	// Bug - does not take into account if m == 1
	for (int reverseCount = 0; reverseCount < len; reverseCount++) {
		savenext = l->next;

		// set last in reverse, first in the original list
		if (! last_in_reverse) 
			last_in_reverse = l;
	
		l->next = reverseList;
		reverseList = l;
		l = savenext;
	}

	if (from_first) {
		list = reverseList;
	} else {
		// attach to the non-reversed list
		prev->next = reverseList;
	}

	last_in_reverse->next = savenext;
}

// find the sum of last consecutive K nodes
// use sliding window technique
template <typename T>
int SinglyList<T>::sumOfLastK(int k) {
	if (list == nullptr) 
		return -1;
	
	int sum = 0;
	int window = 1;

	Node<T> *first = list;
	Node<T> *second = list;

	// start with this, if last K nodes not found return -1
	sum = list->data;
	// 1 2 3 4 5
	while (second != nullptr) {
		if (window < k && second->next == nullptr) {
			sum = -1;
			break;
		}
		if (window > k) {
			sum -= first->data;
			first = first->next;
			window--;
		}

		if (second->next) {
			second = second->next;
			window++;
			sum += second->data;
		} else {
			second = second->next;
		}
	}
	return sum;
}

// Shuffle a list
// This assumes that there are even number of elements in the list
template <typename T>
void SinglyList<T>::shuffleList() {
	// find the halfway point
	// 2 pointer method
	Node<T> *s = list;
	Node<T> *f = list->next;

	// since there is a guarantee that there will
	// be even number of nodes, we can only check
	// if the next is not null for fast ptr
	while (f->next) {
		s = s->next;
		f = f->next->next;
	}
	// 2 lists will be s and f
	f = s->next;
	s->next = nullptr;
	s = list;
	list = f; // head of the list starts at the second list

	// braid now!
	while (s && f) {
		Node<T> *savefnext = f->next;
		Node<T> *savesnext = s->next;
		
		f->next = s;
		s->next = savefnext;
		f = f->next->next;
		s = savesnext;
	}	
}

// Max sum of K consecutive nodes in the list
template <typename T>
int SinglyList<T>::maxSumOfK(int k) {
	if (list == nullptr)
		return -1;

	Node<T> *first = list;
	Node<T> *second = list;
	int window = 1;
	int maxSum = 0;
	int prevMax = 0;
	int listLen = 0;

	// 1 2 3 4 5 4 3 2 1
	while (second != nullptr) {
		if (window > k) {
			maxSum -= first->data;
			first = first->next;
			window--;
		}
			
		maxSum += second->data;

		if (window == k)
			prevMax = (prevMax > maxSum) ? prevMax : maxSum;
		
		second = second->next;
		window++;
		listLen++;
	}

	// k consecutive nodes was never found
	if (listLen < k) {
		return -1;
	}

	return prevMax;
}

// odd numbered nodes first and then even numbered nodes
template <typename T>
void SinglyList<T>::oddEven() {
	Node<T> *tmpOdd = list;
	Node<T> *evenHead = nullptr;
	Node<T> *tmpEven;
	
	// Join tmpOdd to evenHead at the end
	while (tmpOdd->next) {
		tmpEven = tmpOdd->next;

		tmpOdd->next = tmpEven->next;
		
		if (! evenHead)
			evenHead = tmpEven;

		if (tmpOdd->next)
			tmpOdd = tmpOdd->next;
		
		tmpEven->next = tmpOdd->next;
		tmpEven = tmpEven->next;
	}

	tmpOdd->next = evenHead;
}

// slowPtr moves 1 step closer than the regular "tmp" pointer
// Can be solved through tortoise and hare logic!
// 1 2 3
template <typename T>
void SinglyList<T>::deleteOddPos() {
	Node<T> *fastPtr = list;
	Node<T> *slowPtr = list;
	bool start = true;

	if (list == nullptr)
		return;
	else if (list->next == nullptr) {
		delete list;
		return;
	}

	while (slowPtr != nullptr && fastPtr != nullptr) {
		slowPtr->next = fastPtr->next;
		delete(fastPtr);
		
		slowPtr = slowPtr->next;
		if (slowPtr != nullptr)
			fastPtr = slowPtr->next;

		// this is the only change with this and deleteEvenPos
		if (start) {
			list = slowPtr;
			start = false;
		}
	}
}

// Get decimal from a linked list
template <typename T>
int SinglyList<T>::getInt() {
	Node<T> *head = list;

	if (! head)
		return 0;

	std::vector<int> pos;
	int count = 0;
	int res = 0;

	while (head) {
		if (head->data)
			pos.push_back(count);

		count++;
		head = head->next;
	}
	count--;

	// iterate the vector now
	for (auto it = pos.begin(); it != pos.end(); it++) {
		res += 1 << (count - *it);
	}
	
	return res;
}

// Remove a node
template <typename T>
void SinglyList<T>::removeNode(T data) {
	Node<T> *copy = list;
	bool newHead = false;
	Node<T> *prev = list;

	if (! list)
		return ;

	// special case for head node
	while (! newHead && copy) {
		if (copy->data != data) {
			newHead = true;
			copy = copy->next;
		} else {
			Node<T> *savenext = copy->next;
			delete(list);
			list = savenext;
			prev = list;
			copy = list;
		}
	}
       
	while (copy) {
		if (copy->data == data) {
			Node<T> *savenext = copy->next;
			delete(copy);
			prev->next = savenext;
			copy = savenext;
			continue;
		}
		prev = copy;
		copy = copy->next;
	}
}

// Use fast and slow pointer logic
template <typename T>
void SinglyList<T>::deleteEvenPos() {
	Node<T> *fastPtr = list;
	Node<T> *slowPtr = list;

	if (list == nullptr || list->next == nullptr) {
		return;
	}

	fastPtr = list->next;

	while (slowPtr != nullptr && fastPtr != nullptr) {
		slowPtr->next = fastPtr->next;
		delete(fastPtr);
		slowPtr = slowPtr->next;
		if (slowPtr != nullptr)
			fastPtr = slowPtr->next;
	}
}
