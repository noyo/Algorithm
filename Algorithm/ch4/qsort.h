
//void ;

int partion(int a[], int low, int high) {
	int guard = a[low];
	while(low < high) {
		while(low < high && guard <= a[high]) {
			high--;
		}
		if(low < high) {
			a[low++] = a[high];
		}
		while(low < high && guard >= a[low]) {
			low++;
		}
		if(low < high) {
			a[high--] = a[low];
		}
	}
	a[low] = guard;
	return low;
}

void qsort(int a[], int low, int high) {
	if(low < high) {
		int pivot = partion(a, low, high);
		qsort(a, low, pivot - 1);
		qsort(a, pivot + 1, high);
	} 
}
