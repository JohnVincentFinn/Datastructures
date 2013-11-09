/*
 * =====================================================================================
 *
 *       Filename:  list.h
 *
 *    Description:  linked list
 *
 *    TODO: Write doubly linked list and skip list
 *
 *        Version:  1.0
 *        Created:  06/17/2012 03:53:44 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  John Finn (JF), johnvincentfinn@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef _LIST_H__
#define _LIST_H__
#include <stdlib.h>
#include "../generic/generic.h"

/*
 * =====================================================================================
 *        Class:  List
 *  Description:  This is a singly linked list implementation
 * =====================================================================================
 */
template<class T>
class List: public generic<T>, iterable<T> {
private:
    /* ====================  DATA MEMBERS  ======================================= */
	struct link {
		T    *node;
		link *next;
	};

	link *head;
	link **tail;
    int length;

	link *get_head();	
	link **get_tail();	

public:
    /*
     * =====================================================================================
     *        Class:  iterator
     *  Description:  is used to iterate through the list
     * =====================================================================================
     */
	class iterator: public iterable<T>::iterator {
	public:

        /* ====================  LIFECYCLE     ======================================= */
        iterator();                             /* constructor      */
        iterator( const iterator &other );   /* copy constructor */
        ~iterator();                            /* destructor       */

		iterator( List *owner, link *start );
		
        /* ====================  ACCESSORS     ======================================= */
		T next();
		T get();

        /* ====================  MUTATORS      ======================================= */
		void insert( T *node ); // not implemented
		void set( T *node );    // not implemented

        bool end();
        bool start();

        /* ====================  OPERATORS     ======================================= */

        iterator& operator = ( const iterator &other ); /* assignment operator */

		T *operator+( T node );
		T *operator-( T node );
		T *operator++();      // prefix
		T *operator++( int ); // suffix
		bool operator==( T node );
		bool operator==( List l );
		bool operator==( iterator *iter );
		bool operator!=( iterator *iter );

	private:
        /* ====================  DATA MEMBERS  ======================================= */
		link *current;
        List *iterable;

    }; /* -----  end of class Iterator  ----- */

    /* ====================  LIFECYCLE     ======================================= */
    List();                             /* constructor */
    List ( const List &other );   /* copy constructor */
	~List();                            /*  destructor */

    /* ====================  MUTATORS      ======================================= */
	void add( T node );
	void add_front( T node );
	void add_back( T node );
	void splice( List splicee );
	T    remove_front();
	T    get();

    /* ====================  ACCESSORS     ======================================= */
	List<T>::iterator *begin();
	List<T>::iterator *end();

    /* ====================  OPERATORS     ======================================= */

    List& operator=( const List &other ); /* assignment operator */

	void operator+( T node ); // same as add
	void operator+( List l ); // same as splice
	T operator--();        // same as remove front
	T operator--( int );

    friend class iterator;
}; /* -----  end of class List  ----- */

#if 0
    /*
     * =====================================================================================
     *        Class:  iterator
     *  Description:  is used to iterate through the list
     * =====================================================================================
     */
	class iterator {
	public:

        /* ====================  LIFECYCLE     ======================================= */
        iterator();                             /* constructor      */
        iterator( const iterator &other );   /* copy constructor */
        ~iterator();                            /* destructor       */

		iterator( link *start );
		
        /* ====================  ACCESSORS     ======================================= */
		T next();
		T get();

        /* ====================  MUTATORS      ======================================= */
		void insert( T *node ); // not implemented
		void set( T *node );    // not implemented

        bool end();
        bool start();

        /* ====================  OPERATORS     ======================================= */

        iterator& operator = ( const iterator &other ); /* assignment operator */

		T *operator+( T node );
		T *operator-( T node );
		T *operator++();      // prefix
		T *operator++( int ); // suffix
		bool operator==( T node );
		bool operator==( List l );
		bool operator==( iterator *iter );
		bool operator!=( iterator *iter );

	private:
        /* ====================  DATA MEMBERS  ======================================= */
		link *current;

    }; /* -----  end of class Iterator  ----- */
#endif
#include "list.hxx"
#include "list_iterator.hxx"
#endif
