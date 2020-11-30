/*
 * An implementation of hash-table using seperate chaining with a linked list.
 * Author : Aiman Rafeed
 * rafeedaiman@gmail.com
 *  
*/


#include <iostream>

using namespace std;

template <class K, class V>
class Entry
{
	private:
		int hash;
		K key;
		V value;
	
	public:
		Entry(K key, V value)
		{
			this->key = key;
			this->value = value;
			this->hash = key.hashCode();
		}
		
		bool equals(Entry<K,V> other)
		{
			if ( hash != other.hash) return false;
			// return key.equals( other.key );
			return key == other.key;
		}
		
		/*
		string ToString()
		{
			return key + " => " + value;
		}
		*/
		void ToString()
		{
			cout << key << " => " << value << "\n";
		}
};

int main()
{
	
	cout << "\nReturning ...\n";
	return 0;
}
