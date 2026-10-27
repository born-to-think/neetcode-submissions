class WordDictionary {
public:
struct Node{
        array<Node *,26> childs{};
        bool end_of_word = false;
    };

    Node* Root;

    WordDictionary() {
        Root = new Node();
    }
    
    void addWord(string word) {
        Node* curr = Root;
        for(char c:word){
            int i = c-'a';
            Node* temp = curr->childs[i];
            if(!temp ) {
                temp = new Node();
                curr->childs[i] = temp;
            }
            curr = temp;
        }
        curr->end_of_word = true;
    }
    
    bool search2(Node *curr,string::iterator start, const string::iterator& end){
        if(start==end)return curr->end_of_word;
        if(*start != '.'){
            Node* temp = curr->childs[*start - 'a'];
            return temp && search2(temp, start+1, end);
        }
        
        for(int i = 0; i<26; i++)
        {
            Node* temp = curr->childs[i];
            if(temp && search2(temp, start+1, end))return true;
        }
        return false;
    }

    bool search(string word) {
        auto start = word.begin();
        auto end = word.end();
        return search2(Root, start, end);
    }
};
