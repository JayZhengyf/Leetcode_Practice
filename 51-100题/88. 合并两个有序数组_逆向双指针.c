// 逆向双指针法比起双指针法减少了（m+n）的空间使用

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
	int p1 = m - 1, p2 = n - 1;
	int tail = m + n -1;
	int cur;
	while (p1 >= 0 || p2 >= 0) {
		if (p1 == -1) {
			cur = nums2[p2--];
		} else if(p2 == -1) {
			cur = nums1[p1--];
		} else if (nums1[p1] > nums2[p2]) {
			cur = nums1[p1--];
		} else {
			cur = nums2[p2--];
		}
		nums1[tail--] = cur;
	}
}