#include<bits/stdc++.h>
using namespace std;
/**
this problem is solved.
https://www.hackerrank.com/challenges/contacts/problem?isFullScreen=true
*/
typedef struct Node
{
	struct Node* links[26];
	bool flag = false;
	int cp = 0, cd = 0;

	bool containsKey(char ch){
        return links[ch-'a'] != NULL;
	}
	void put(char ch, Node* node){
        links[ch-'a'] = node;
	}
    Node *get(char ch){
        return links[ch-'a'];
    }
    void increasePrefix(){
        cp++;
    }
    void increaseEndWith(){
        cd++;
    }
    void setEnd(){
        flag = true;
    }
    bool isEnd(){
        return flag;
    }

}Node;

class Trie{
private:
    Node* root; //diclare a pointer Node datatype
public:
    // initialize root with c++ new operator
    // to allocating dynamic memory
	Trie(){
		root = new Node();
		// Node temp; root = &temp; is it possible?
	}
    void insert(string word){
        Node* head = root;
        for(int i=0; i<word.size(); i++){
             if(!head->containsKey(word[i])){
                head->put(word[i], new Node());
             }
             head = head->get(word[i]);
             head->increasePrefix();
        }
        head->increaseEndWith();
    }

    /** Returns if there is any word in the trie that end with given word  **/
    bool search(string word){
        Node* head = root;
        for(int i=0; i<word.size(); i++){
            if(!head->containsKey(word[i])){
                return false;
            }
            head = head->get(word[i]);
        }
        return head->isEnd();
    }
    /** Returns if there is any word in the trie that starts with the given prefix  **/
    bool startsWith(string prefix){
        Node* head = root;
        for(int i=0; i<prefix.size(); i++){
            if(!head->containsKey(prefix[i])){
                return false;
            }
            head = head->get(prefix[i]);
        }
        return true;
    }
    /** Returns the number of word whose equal to given word  **/
    int countWordsEqualTo(string word){
        Node* head = root;
        for(int i=0; i<word.size(); i++){
            if(!head->containsKey(word[i])){
                return 0;
            }
            head = head->get(word[i]);
        }
        return head->cd;
    }
    /** Returns the number of word for given prefix **/
    int countWordsStartingWith(string prefix){
        Node* head = root;
        int ans = 0;
        for(int i=0; i<prefix.size(); i++){
            if(!head->containsKey(prefix[i])){
                return 0;
            }
            head = head->get(prefix[i]);
        }
        return head->cp;
    }
};

/*
    (1<<31) is greater then 1e9
*/

int main(){
	Trie t;
    int n; cin>>n;
    for(int i=1; i<=n; i++){
        string type,s;
        cin>>type>>s;
        if(type == "add"){
            t.insert(s);
        }
        else{
            cout<<t.countWordsStartingWith(s)<<endl;
        }
    }

	return 0;
}
