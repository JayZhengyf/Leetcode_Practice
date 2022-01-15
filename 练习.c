// 第一题 哈希解法
struct hashTable {
	int key;
	int val;
	UT_hash_handle hh;
};

struct hashTable* hashtable;

struct hashTable* find(int ikey) {
	struct hashTable *tmp;
	HASH_FIND_INT(hashtable, &ikey, tmp);
	return tmp;
}

void insert(int ikey, int ival) {
	struct hashTable* it = find(ikey);
	if(it = NULL) {
		struct hashTable *tmp = malloc(sizeof(struct hashTable));
		tmp->key = ikey;
		tmp->val = ival;
		HASH_ADD_INT(hashtable, key, tmp);
	}
	else {
		it->val = ival;
	}
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
	hashtable = NULL;
	for (int i = 0; i < numsSize; i++) {
		struct hashTable* it = find(target - nums[i]);
		if (it != NULL) {
			int* ret = malloc(sizeof(int) * 2)
			ret[0] = it->val;
			ret[1] = i;
			*returnSize = 2;
			return ret;
		}
		// 数值是key,数值在数组中的位置是val
		insert(nums[i], i);
	}
	*returnSize = 0;
	return NULL;
}

//第二题

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	struct ListNode *head = NULL, *tail = NULL;
	int carry = 0;
	
	while (l1 || l2) {
		// 如果l1不为空则将l1->value赋值给n1,否则给n1赋0
		int n1 = l1 ? l1->val: 0;
		int n2 = l2 ? l2->val: 0;
		int sum = n1 + n2 + carry;
		
		if (!head) {
			// 初始化，第一次
			head = tail = malloc(sizeof(struct ListNode));
			tail->val = sum % 10;
			tail->next = NULL;
		}
		else {
			tail->next = malloc(sizeof(struct ListNode));
			tail->next->val = sum % 10;
			tail->next->next = NULL;
			tail = tail->next;
		}
		if (l1) {
			l1 = l1->next;
		}
		if (l2) {
			l2 = l2->next;
		}
		carry = sum / 10;
	}
	// 处理最后一位进位的情况
	if (carry > 0) {
		tail->next = malloc(sizeof(struct ListNode));
		tail->next->val = carry;
		tail->next->next = NULL;
		tail = tail->next;
	}
	return head;
}