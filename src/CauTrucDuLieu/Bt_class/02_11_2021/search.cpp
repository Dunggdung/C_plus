int linearSearch (int a[], int n, int key){
    for(int i = 0; i < n; i++){
        if(a[i] == key)
            return i;
    }
    return -1;
}
int linearSearch (int a[], int n, int key){
    int i = 0;
    while(i<n){
        if(a[i] == key)
        return i;
        i++;
    }
    return -1;
}
int linearSearch (int a[], int n, int key){
    while(n--){
        if(a[n] == key)
        return n;
    }
    return -1;
}
int binarySearch(int a[], int n, int key){
    int left = 0,right = n -1,mid;
    while(left <= right){
        mid = (left + right)/2;
        if(a[mid] == key)
            return mid;
        else if(a[mid] < key)
            left = mid+1;
        else 
            right = mid-1;
    }
    return -1;
}