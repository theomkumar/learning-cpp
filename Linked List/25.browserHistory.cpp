/*
### APPROACH 1: using stl list(doubly linked list)
    list<string> history;
    list<string> :: iterator it;
    
    BrowserHistory(string homepage) {
        history.push_back(homepage);
        it = history.begin();
    }
    
    void visit(string url) {
        //to delete all the elements after current iterator's next.
        auto del = it; //list<string> :: iterator del = it;
        del++;
        history.erase(del, history.end());        
        
        history.push_back(url);
        it++;
    }
    
    string back(int steps) {
        while (steps-- && it != history.begin())
            it--;
        return *it;
    }
    
    string forward(int steps) {
        while (steps-- && it != --history.end())  
            it++;
        return *it;
    }
};

### Approach 2: 

class Node
{
    public:
    string url;
    Node *prev, *next;
    
    Node (string url)
    {
        this -> url = url;
        prev = next = NULL;
    }
};
class BrowserHistory {
public:
    //dummy, we'll use this to traverse. also element after that will act as head.
    Node *curr = new Node("");
    
    BrowserHistory(string homepage) {
        Node* newTab = new Node(homepage);
        newTab -> prev = curr;
        curr -> next = newTab;
        curr = newTab;
    }
    
    void visit(string url) {
        Node* nextNode = curr -> next;//(optional) we'll use this pointer to delete forward elements
        
        Node* newTab = new Node(url);
        newTab -> prev = curr;
        curr -> next = newTab;
        curr = newTab;
        
        //freeing up memory (optional)
        while (nextNode)
        {
            Node* temp = nextNode;
            nextNode = nextNode -> next;
            delete temp;
        }
    }
    
    string back(int steps) {
        while (steps-- && curr -> prev -> url != "")
            curr = curr -> prev;
        return curr -> url;
    }
    
    string forward(int steps) {
        while (steps-- && curr -> next)
            curr = curr -> next;
        return curr -> url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
*/