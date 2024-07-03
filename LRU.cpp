#include <list>
#include <unordered_map>
#include <iostream>
using namespace std;


//NODE TO STORE THE DATA (LINKED LIST)
class Node{
	 public:
	 	string key;
	 	int value;
	 	
	 	Node(string key,int value){
	 		this->key = key;
	 		this->value = value;
		 }
	
};



//LRU CHACHE DATA STRUCTURE
class LRUCache{
	public:
		int maxSize;
		list<Node> l;
		unordered_map<string,list<Node>::iterator> m;
		
		LRUCache(int maxSize){
			this->maxSize = maxSize > 1 ? maxSize : 1 ;
		}
		
		void insertKeyValue(string key,int value){
			// 2 cases
			
			if(m.count(key)!=0){
				//UPDATE
				auto it = m(key);
				it->value = value;
			}  
			else {
				//CACHE IS FULL
				
				//REMOVE LRU ITEM
				
				if(l.size()==maxSize){
					
					Node last = l.back();
					m.erase(last.key);
					l.pop_back(); //remove from likedlist
				}
				
				Node n(key,value);
				l.push_front(n);
				m[key] = l.begin();
				
			}
		}
		
		int* getValue(string key){
			
			//GET KEY FROM LRU
			
			if(m.count(key)!=0){
				
				auto it = m[key];
				
				int value = it->value;
				l.push_front(*it);
				l.erase(it);
				m[key] = l.begin();
				return &l.begin()->value;
			}
			
			return NULL;
		}
		
		string mostRecentKey(){
			   
			   return l.front().key;
		}
};


int main(){
	
	LRUCache lru(3);
	lru.insertKeyValue("Mango",10);
	lru.insertKeyValue("Banana",20);
	lru.insertKeyValue("Apple",30);
	
	cout<< lru.mostRecentKey()<<endl;
	
	lru.insertKeyValue("Mango",40);
	cout<<lru.mostRecentKey()<<endl;
	
	lru.insertKeyValue("Pineapple",20);
	
	if(lru.getValue("Apple")==NULL){
		
		cout<<"Apple doesn't exist"<<endl;
	}
	
	if(lru.getValue("Guava")==NULL){
		
		cout<<"Guava doesn't exist"<<endl;
	}
	
	if(lru.getValue("Banana")==NULL){
		
		cout<<"Banana doesn't exist"<<endl;
	}
	
	
	return 0;
}
