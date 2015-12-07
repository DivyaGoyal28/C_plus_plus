#include "iostream"
#include "map"
#include <assert.h>
#include <map>
#include <limits>


#define RANGE_MIN 0
#define RANGE_MAX 10

//Template
template<class K, class V>
class interval_map {
    friend void IntervalMapTest();

private:
    std::map<K,V> m_map;

public:
    // constructor associates whole range of K with val by inserting (K_min, val)
    // into the map
    interval_map( V const& val) {
        K start = RANGE_MIN ;//  std::numeric_limits<K>::min();
        K end =   RANGE_MAX ;//  std::numeric_limits<K>::max();
        std::cout << "Range is " << start<< " " <<end << std::endl;
        //for(K i = start; i<end; i++)
        m_map.insert(m_map.begin(),std::make_pair(start,val));

    };

    // Assign value val to interval [keyBegin, keyEnd).
    // Overwrite previous values in this interval.
    // Do not change values outside this interval.
    // Conforming to the C++ Standard Library conventions, the interval
    // includes keyBegin, but excludes keyEnd.
    // If !( keyBegin < keyEnd ), this designates an empty interval,
    // and assign must do nothing.
    void assign( K const& keyBegin, K const& keyEnd, const V& val ) {
        // INSERT YOUR SOLUTION HERE
        if (!( keyBegin < keyEnd ))
        {
            //do nothing
            return ;
        }
        std::cout << "Assigning Range ["<<keyBegin<< ","<< keyEnd <<") " << "With "<<val << std::endl;

        K start = keyBegin ;//  std::numeric_limits<K>::min();
        K end =   keyEnd  ;//  std::numeric_limits<K>::max();
        std::cout << "Range is " << start<< " " <<end << std::endl;

        //Make an iterator for key and range
        std::map < int, char >::iterator it = m_map.begin ();
        std::cout << "Comparing " << (m_map.end())->first <<" " << keyBegin << std::endl;



        //one method is use the data structure of type interval_map to pull out lowest
        //ALMOST WORKING
        if((m_map.end())->first < keyBegin) {

            //We are beyond range
            V orig_value_in_bigger_range = ( --m_map.upper_bound(keyBegin) )->second;

            //Fill the lower value upto the lower key

            //try to replace this for loop by similar to the next while loop
            //	SEE IF WE CAN AVOID THIS FILLING
            // THis beaks the rule of changing values outside the interval
            for(K i=(m_map.end())->first; i<keyBegin; i++)
            {
                std::cout<< i<<"---" << (--m_map.upper_bound(i))->second<<std::endl;
                //Using the given operators to fill the array upto beginning
                m_map.insert(m_map.begin(),std::make_pair(i,(--m_map.upper_bound(i))->second));
            }

            //Use the below method instead of for loop
            //Tricks
            //Get the key value at last place by --m_map.upper_bound(valk))->first
            //Get the key value at next place by m_map.upper_bound(valk))->first
            //Don't use increment operator to increment, add the value to map, see the last of map and get incremented value;

            K valk;
            while(m_map.end()->first < keyEnd) {
                valk = keyBegin;
                std::cout << "Inserting " << val << "at "<< valk << std::endl;
                m_map.insert(m_map.end(),std::make_pair((m_map.upper_bound((--m_map.upper_bound(valk))->first))->first,val));
                valk = m_map.upper_bound(val)->first;
            }
            //Add original value beyong this key for accessibility
            m_map.insert(m_map.end(),std::make_pair((m_map.upper_bound(keyEnd))->first,orig_value_in_bigger_range));


        }
        //NEEDS TWEAKING 
        else {
            //We are within range
            K key_before_keyBegin = (--m_map.upper_bound(keyBegin))->first;
            std::map<int,char>::iterator Iter_for_key_begin = m_map.upper_bound(keyBegin); //How to templatise it
            int key_iter= keyBegin;
            
            while(key_iter < keyEnd) {
                std::cout << "Inserting " << val <<" at " << (--m_map.upper_bound(key_iter))->first << std::endl;
                m_map.erase((--m_map.upper_bound(key_iter))->first);
                m_map.insert((--m_map.upper_bound(key_iter)),std::make_pair(key_iter,val));
               // m_map.insert(std::make_pair(key_iter,val));
                std::cout << "Value after Inserting is  " <<  (--m_map.upper_bound(key_iter))->second << std::endl;
                key_iter = m_map.upper_bound(key_iter)->first;
            }
        }
    }


    // look-up of the value associated with key
    V const& operator[]( K const& key ) const {
        //std::cout << (--m_map.upper_bound(key))->first <<std::endl;
        return ( --m_map.upper_bound(key) )->second;
    }

    int debug()
    {
        //std::map<K,V>::iterator it = m_map.begin ();
        std::map < int, char >::iterator it = m_map.begin ();
        std::cout << "mymap contains:\n";

        for (it = m_map.begin (); it != m_map.end (); ++it)
        {
            std::cout << it->first << " => " << it->second << '\n';
        }
    }

    

};

// Many solutions we receive are incorrect. Consider using a randomized test
// to discover the cases that your implementation does not handle correctly.
// We recommend to implement a function IntervalMapTest() here that tests the
// functionality of the interval_map, for example using a map of unsigned int
// intervals to char.


//Main
int main() {
    interval_map<int,char> a('B');
    std::cout << std::numeric_limits<int>::min() ;
    a.debug();
    std::cout << a [4] << std::endl;

    //a.assign(1,10,'C');

    a.assign(3,5,'K');

    //a[4] = 't';
    a.debug();
    a.assign(2,4,'L');
    a.debug();
}

