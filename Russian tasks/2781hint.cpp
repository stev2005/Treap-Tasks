    void push_into_stack(Node* cur, stack<Node*> &st){
        while (!st.empty() && st.top()->pr > cur->pr)
            st.pop();
        if (!st.empty())
            if (!cur->par || cur->par->pr < st.top()->pr)
                cur->par = st.top();
        st.push(cur);
    }

    void build(int n, tuple<int, int, int> *el){
        vector<Node*> nodes;
        for (int i = 1; i <= n; ++i)
            nodes.push_back(new Node(get<0>(el[i]), get<1>(el[i]), get<2>(el[i])));
        stack<Node*> st;
        for (int i = 0; i < n; ++i)
            push_into_stack(nodes[i], st);
        while (!st.empty())
            st.pop();
        for (int i = n - 1; i >= 0; --i)
            push_into_stack(nodes[i], st);
        for (int i = 0; i < n; ++i)
            if (nodes[i]->par){
                if (nodes[i]->par->key >= nodes[i]->key)
                    nodes[i]->par->l = nodes[i];
                else nodes[i]->par->r = nodes[i];
            }
        Node *minpr = nodes[0];
        for (int i = 1; i <n; ++i)
            if (nodes[i]->pr < minpr->pr)
                minpr = nodes[i];
        root = minpr;
    }
