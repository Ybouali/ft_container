
#include <iostream>
#include <vector>
#include <iterator>
#include <typeinfo>


#include "../iterator/random_access_iterator.hpp"
#include "../vector.hpp"

#define N 3

int main()
{
    std::cout << "--------- TEST RANDOM ACCESS ITERATOR ---------------------" << std::endl << std::endl;

    std::allocator<int> alloc;
    ft::random_access_iterator<int> it, it1;

    it = alloc.allocate(3);
    it1 = it;
    for (int i = 0; i < 3; i++)
    {
        *it = i;
        it++;
    }

    std::cout << "--------- TEST THE PRE INCREMENT ---------------" << std::endl << std::endl;
    for (int i = 0; i < 3; i++)
    {
        std::cout << "      *it1 = " << *it1 << std::endl;
        ++it1;
    }
    std::cout << "--------- TEST THE POST DEINCREMENT ---------------" << std::endl << std::endl;
    for (int i = 0; i < 3; i++)
    {
        it1--;
        std::cout << "      *it1 = " << *it1 << std::endl;
    }
        
    for (int i = 0; i < 3; i++)
        it1++;
        
    std::cout << "--------- TEST THE PRE DEINCREMENT ---------------" << std::endl << std::endl;
    for (int i = 0; i < 3; i++)
    {
        --it1;
        std::cout << "      *it1 = " << *it1 << std::endl;
    }

    for (int i = 0; i < 3; i++)
        it--;

    std::cout << "--------- TEST THE LOGICAL OPERATOR == -----------" << std::endl << std::endl;
    if (it == it1)
        std::cout << "      YES it == it1" << std::endl;
    else
        std::cout << "      NO it == it1" << std::endl;
    std::cout << "      it++" << std::endl;
    it++;
    if (it == it1)
        std::cout << "      YES it == it1" << std::endl;
    else
        std::cout << "      NO it == it1" << std::endl;
        
    std::cout << "--------- TEST THE LOGICAL OPERATOR != ---------------" << std::endl << std::endl;

    if (it != it1)
        std::cout << "      YES it != it1" << std::endl;
    else
        std::cout << "      NO it != it1" << std::endl;
    it--;
    std::cout << "      it--" << std::endl;
    if (it != it1)
        std::cout << "      YES it != it1" << std::endl;
    else
        std::cout << "      NO it != it1" << std::endl;
        
    std::cout << "--------- TEST THE LOGICAL OPERATOR < ---------------" << std::endl << std::endl;
    if (it < it1)
        std::cout << "      YES it < it1" << std::endl;
    else
        std::cout << "      NO it < it1" << std::endl;
    std::cout << "--------- TEST THE LOGICAL OPERATOR <= ---------------" << std::endl;
    if (it <= it1)
        std::cout << "      YES it <= it1" << std::endl;
    else
        std::cout << "      NO it <= it1" << std::endl;

    std::cout << "--------- TEST THE LOGICAL OPERATOR > ---------------" << std::endl << std::endl;
    if (it > it1)
        std::cout << "      YES it > it1" << std::endl;
    else
        std::cout << "      NO it > it1" << std::endl;

    std::cout << "--------- TEST THE LOGICAL OPERATOR >= ---------------" << std::endl << std::endl;
    if (it >= it1)
        std::cout << "      YES it >= it1" << std::endl;
    else
        std::cout << "      NO it >= it1" << std::endl;

    std::cout << "--------- TEST THE OPERATOR OBJECT + NUMBER ----------" << std::endl << std::endl;
    it = it + 1;
    std::cout << "      it + 1 = " << *it << std::endl;
    std::cout << "--------- TEST THE OPERATOR OBJECT - NUMBER ---------------" << std::endl << std::endl;
    it = it - 1;
    std::cout << "      it - 1 = " << *it << std::endl;

    std::cout << "--------- TEST THE OPERATOR [] ---------------" << std::endl << std::endl;
    for (int i = 0; i < 3; i++)
        std::cout << "      it[" << i <<  "] = " << it[i] << std::endl;

    it = it + 1;
    it1 = it1 + 1;

    std::cout << "--------- TEST THE OPERATOR OBJECT - OBJECT ---------------" << std::endl << std::endl;

    std::cout << "      it = " << *it << " it1 = " << *it1 << std::endl;
    std::cout << "      it1 - it = " << it1 - it << std::endl;
    std::cout << "      it - it1 = " << it - it1 << std::endl;
    it1++;
    it = it - 1;
    std::cout << "      it1++" << std::endl;
    std::cout << "      it - 1" << std::endl;
    std::cout << "      it = " << *it << " it1 = " << *it1 << std::endl;
    std::cout << "      it1 - it = " << it1 - it << std::endl;
    std::cout << "      it - it1 = " << it - it1 << std::endl;

    std::cout << "--------- TEST THE OPERATOR *OBJECT++ && *OBJECT-- ---------------" << std::endl << std::endl;
    *it++;
    std::cout << "      *it++ = " << *it << std::endl;   
    *it--;
    std::cout << "      *it-- = " << *it << std::endl;
    
    std::cout << "--------- TEST THE OPERATOR OBJECT += NUMBER ---------------" << std::endl << std::endl;
    it += 2;
    std::cout << "      it += 2 = " << *it << std::endl;
    std::cout << "--------- TEST THE OPERATOR OBJECT -= NUMBER ---------------" << std::endl << std::endl;
    it -= 2;
    std::cout << "      it -= 2 = " << *it << std::endl;

    std::cout << "--------- TEST THE OPERATOR NUMBER + OBJECT  ---------------" << std::endl << std::endl;
    it = 2 + it;
    std::cout << "      2 + it; " << *it << std::endl;

    std::cout << "--------- TEST POINTER ITERATOR && REFERENCE ---------------" << std::endl << std::endl;
    ft::random_access_iterator<int> *t = NULL;
    t = &it;
    ft::random_access_iterator<int> &t1 = *t;


    std::cout << "      POINTER **t = " << **t << std::endl;
    std::cout << "     REFERENCE *t = " << *t1 << std::endl;
}