class PrefixTree {
public:
    struct Node{
        char c;
        Node *childs[26];
        bool end_of_word ;

        Node(char ch){
            c = ch;
            for(int i=0;i<26;i++)childs[i]=nullptr;
            end_of_word = false;
        }

    };

    Node* Root;

    PrefixTree() {
        Root = new Node(' ');    
    }
    
    void insert(string word) {
        Node* curr = Root;
        for(char c:word){
            int i = c-'a';
            Node* temp = curr->childs[i];
            if(!temp ) {
                temp = new Node(c);
                curr->childs[i] = temp;
            }
            curr = temp;
        }
        curr->end_of_word = true;
    }
    
    bool search(string word) {
        Node* curr = Root;
        for(char c:word){
            if(! (curr->childs[c-'a']) )return false;
            curr = curr->childs[c-'a'];
        }
        return curr->end_of_word;
        
    }
    
    bool startsWith(string prefix) {
        Node* curr = Root;
        for(char c:prefix){
            if(! (curr->childs[c-'a']) )return false;
            curr = curr->childs[c-'a'];
        }
        return true;
    }
};
