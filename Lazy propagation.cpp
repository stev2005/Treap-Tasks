struct Treap
{
    struct Node
    {
        Node *l,*r;
        int key,pr,sz;
        bool rev;///is this subtree reveresed
        Node(){l = r = NULL;}
        Node(int _key)
        {
            rev = false;
            ///...
        }
        void con(){
            ///...
        }
    };

    Node *root;
    Treap(){root=NULL;}

    void push(Node *T)
    {
        if(T&&T->rev)
        {
            T->rev = false;
            swap(T->l, T->r);
            if (T->l) T->l->rev ^= true;
            if (T->r) T->r->rev ^= true;
        }
    }

    void Split(Node *T,Node *&L,Node *&R,int key)
    {

        if(T==NULL)
        {
            L=R=NULL;
            return;
        }
        push(T);
        ///The rest is the same as the normal Split()
    }

    void Merge(Node *&T,Node *L,Node *R)
    {
        push(L);push(R);
        ///The rest is the same as the normal Merge()
    }

    void Split_sz(Node *T,Node *&L,Node *&R,int sz)
    {
        if(T==NULL)
        {
            L=R=NULL;
            return;
        }
        push(T);
        ///The rest is the same as the normal Split_sz()
    }

    void reverse_seg(Node *T,int l,int r)
    {
        Node *L,*R,*N;
        Split_sz(root,L,R,r);
        Split_sz(L,L,N,l-1);
        N->rev^=true;
        Megre(L,L,N);
        Merge(root,L,R);
    }
};
