struct Status {
	/*
	lSum表示[l,r]区间中，以l为左端点的最大子段和
	rSum表示[l,r]区间中，以r为右端点的最大子段和
	mSum表示[l,r]区间的最大子段和
	iSum表示[l,r]的区间和
	*/
	int lSum, rSum, mSum, iSum;
};

struct Status pushUp(struct Status l, struct Status r) {
	int iSum = l.iSum + r.iSum;
	int lSum = fmax(l.lSum, l.iSum + r.lSum);
	int rSum = fmax(r.rSum, r.iSum + l.rSum);
	// mSum可能跨越区间也可能不跨越
	int mSum = fmax(fmax(l.mSum, r.mSum), l.rSum + r.lSum);
	return (struct Status) {lSum, rSum, mSum, iSum};
}

// get(a, l, r)表示查询a序列[l, r]区间内的最大子段和
struct Status get(int* a, int l, int r) {
	if (l == r) {
		return (struct Status) {a[l], a[l], a[l], a[l]};
	}
	int m = (l + r) >> 1;
	struct Status lSub = get(a, l, m);
	struct Status rSub = get(a, m + 1, r);
	return pushUp(lSub, rSub);
}

int maxSubArray(int* nums, int numsSize) {
	return get(nums, 0, numsSize - 1).mSum;
}