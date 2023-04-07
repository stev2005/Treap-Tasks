void heapify(Node *T){
    Node *maxi = T;
    if (T->l && T->l->pr > maxi->pr)
        maxi = T->l;
    if (T->r && T->r->pr > maxi->pr)
        maxi = T->r;
    if (maxi != T){
        swap (maxi->pr, T->pr);
        heapify(maxi);
    }
}

Node *Fast_build(int *a, int n){
    ///O(n)
    ///zero based indexes
    ///a: the array from which treap is built
    ///n: count of elements in a
    if (n == 0) return NULL;
    int mid = n/2;
    Node *T = new Node(a[mid]);
    T->l = Fast_build(a, mid);
    T->r = Fast_build(a+mid+1, n - mid - 1);
    heapify(T);
    T->con();
    return T;
}
