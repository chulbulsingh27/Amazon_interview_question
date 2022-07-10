int parcel(int *a, int n) {

	unordered_set<int>set;

	for (int i = 0; i < n; i++) {
		if (a[i] != 0)
			set.insert(a[i]);
	}
	return set.size();
}
