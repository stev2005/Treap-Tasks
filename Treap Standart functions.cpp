struct Treap
{
    struct Node
    {
        Node *l, *r;
        int key, pr, sz;
        Node(){l = r = NULL;}
        Node(int _key){
            key = _key;
            pr = rand();
            sz = 1;
            l = r = NULL;
        }
        void con(){
            sz = 1;
            if (l) sz += l->sz;
            if (r) sz += r->sz;
        }
    };

    Node *root;
    Treap(){root=NULL;}

    void Split(Node *T,Node *&L,Node *&R,int key)
    {
        if(T==NULL)
        {
            L=R=NULL;
            return;
        }
        if(key>=T->key)
        {
            L=T;
            Split(T->r,L->r,R,key);
        }
        else
        {
            R=T;
            Split(T->l,L,R->l,key);
        }
        T->con();
    }

    void Merge(Node *&T,Node *L,Node *R)
    {
        if(L==NULL)
        {
            T=R;
            return;
        }
        if(R==NULL)
        {
            T=L;
            return;
        }
        if(L->pr > R->pr)
        {
            T=L;
            Merge(T->r,L->r,R);
        }
        else
        {
            T=R;
            Merge(T->l,L,R->l);
        }
        T->con();
    }

    void Split_sz(Node *T,Node *&L,Node *&R,int sz)
    {
        if(T==NULL)
        {
            L=R=NULL;
            return;
        }
        int tsz=1;
        if(T->l)tsz+=T->l->sz;
        if(tsz>sz)
        {
            R=T;
            Split_sz(T->l,L,R->l,sz);
        }
        else
        {
            L=T;
            Split_sz(T->r,L->r,R,sz-tsz);
        }
        T->con();
    }

    void Insert(int key)
    {
        Node *L,*R,*N=new Node(key);
        Split(root,L,R,key);
        Merge(L,L,N);
        Merge(root,L,R);
        //delete L;
        //delete R;
    }

    void Delete(int key)
    {
        Node *L,*R,*N;
        Split(root,L,R,key);
        Split(L,L,N,key-1);
        delete N;
        Merge(root,L,R);
        //delete L;
        //delete R;
    }
};
