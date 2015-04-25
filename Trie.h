class Trie {
public:
	struct Node {
		Node(char val):value(val) {}
		~Node() {
			for (int i=0;i<27;++i) {
				if (children[i]) delete children[i];
				children[i]=NULL;
			}
		}
		Node* get(char c, bool auto_create=true) {
			int id=c=='\0'?26:c-'a';
			if (!children[id] && auto_create) {
				children[id]=new Node(c);
				children[id]->parent=this;
				num_children++;
			}
			return children[id];
		}
		bool end() {
			return get('\0',false);
		}
		int num_children{0};
		char value{0};
		Node* parent{NULL};
		Node* children[27]{NULL};
	};
	Trie() {
		_root=new Node(-1);
	}
	~Trie() {
		if(_root) {
			delete _root;
			_root=NULL;
		}
	}
	void add_string(const string & str) {
		auto node=_root;
		for (auto c:str) {
			node=node->get(c);
		}
		node->get('\0');
	}
	
	string search_longest(const string& str) {
	    string ret;
	    bool count[256] = {false};
	    for(auto c : str) count[c] = true;
   
	    function<void(string& ,Node*)> search = [&](string &cur, Node* node){
	        if (!node) return;
	        if (node->end()) {
	            if(cur.length() > ret.size())
	                ret = cur;
	        }
	        for(int i = 0; i < 26; ++i) {
	            if(!node->children[i] || !count[node->children[i]->value]) continue;
				cur+=node->children[i]->value;
	            search(cur, node->children[i]);
				cur.pop_back();
	        }
	    };
		string s{""};
	    search(s, _root);
	    return ret;
	}
	
private:
	Node* _root {NULL};
};