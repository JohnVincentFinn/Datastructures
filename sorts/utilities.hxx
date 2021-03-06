/*
 * =====================================================================================
 *
 *       Filename:  utilities.hxx
 *
 *    Description:  various utilities used by the sorts
 *
 *        Version:  1.0
 *        Created:  03/28/2013 07:51:46 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  John Finn (), johnvincentfinn@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef _UTILITIES_HXX__
#define _UTILITIES_HXX__
#include "utilities.hh"

template <typename T>
bool compare( T a, T b ) {
    return a > b;
}

template <typename T>
void print_array( T arr[], int size ) {

    if( size >= 1 ) {
        printf("{ %d", arr[0]);
        for( int i = 1; i < size; ++i ) {
            printf(", %d", arr[i] );
        }
        printf(" }\n");
    } else {
        printf("{ }\n");
    }

}

#endif
