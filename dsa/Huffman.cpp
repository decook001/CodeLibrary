
struct Node
{
    Node* leftChild;
    Node* rightChild;
    int weight=0;
    int letter=-1;
    Node(int let=-1, int wet=0)
    {
        leftChild=0;
        rightChild=0;
        weight=wet;
        letter=let;
    }
};

struct comp
{
    bool operator () (Node* a, Node* b)
    {
        return (a->weight) > (b->weight) ;
    }
};

struct Huffman
{
    map<int,int> fre;
    Node* root=0;
    map<int, string> code;

    Huffman(map<char,int> frq)
    {
        for(auto [x,y]: frq)
        {
            fre[ x-'a' ]=y;
        }
        build();
        extract_code(root, "", code);
    }

    void build()
    {
        priority_queue<Node*, vector <Node*>, comp > pq;
        for(auto [x,y]: fre )
        {
            Node* node=new Node(x,y);
            pq.push(node);
        }

        while(pq.size())
        {
            if(pq.size()==1)
            {
                root=pq.top();
                pq.pop();
                break;
            }

            Node* node1=pq.top();
            pq.pop();
            Node* node2=pq.top();
            pq.pop();
            Node* par=new Node(-1,node1->weight+node2->weight);
            par->leftChild=node1;
            par->rightChild=node2;
            pq.push(par);

        }
    }

    void extract_code(Node* now,string x, map<int, string>& code)
    {
        if( now->leftChild )
        {
            string y=x+'0';
            extract_code(now->leftChild,  y, code);
        }

        if(now->rightChild)
        {
            string y=x+'1';
            extract_code( now->rightChild, y, code);
        }
        else
        {
            code[now->letter]=x;
        }
    }

    void print_()
    {
        for(auto [x,y]: code)
        {
            cout<<(char)(x+'a')<<" "<<y<<endl;
        }
    }
};





