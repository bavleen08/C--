// SMALLEST AND LARGEST IN ARRAY
int main(){
    int nums[] = {5, 6, 1, 5};
    int size = 4;
    int smallest = INT_MAX;
    int idx = -1;
    for(int i=0; i<size; i++){
        smallest = min(nums[i], smallest);
    }
    cout << "smallest:" << smallest;
    return 0;
}