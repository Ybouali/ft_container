
#include <iostream>

#include "../iterator/reverse_iterator.hpp"
#include "../iterator/random_access_iterator.hpp"

#define N 3

int main()
{
    std::cout << "--------- TEST REVERSE ITERATOR ---------------------" << std::endl << std::endl;

    std::allocator<int> alloc;

    ft::random_access_iterator<int> it;
    it = alloc.allocate(9);
    for (int i = 0; i < 9; i++)
    {
        *it = i;
        it++;
    }

    ft::reverse_iterator<ft::random_access_iterator<int> > rit(it);
    
    std::cout << "--------- TEST THE OPERATOR []            ---------------" << std::endl << std::endl;

    for (int i = 0; i < 9; i++)
        std::cout << "      rit[" << i << "] = " << rit[i] << std::endl;

    std::cout << "--------- TEST THE POST INCREMENT         ---------------" << std::endl << std::endl;
    
    for (int i = 0; i < 9; i++)
    {
        std::cout << "      *rit = " << *rit << std::endl;
        if (i != 8)
            rit++;
    }
    std::cout << "--------- TEST THE POST DEINCREMENT       ---------------" << std::endl << std::endl;
    for (int i = 0; i < 9; i++)
    {
        std::cout << "      *rit = " << *rit << std::endl;
        if (i != 8)
            rit--;
    }

    std::cout << "--------- TEST THE PRE INCREMENT          ---------------" << std::endl << std::endl;
    for (int i = 0; i < 9; i++)
    {
        std::cout << "      *rit = " << *rit << std::endl;
        if (i != 8)
            ++rit;
    }

    std::cout << "--------- TEST THE PRE DEINCREMENT.        ---------------" << std::endl << std::endl;
    for (int i = 0; i < 9; i++)
    {
        std::cout << "      *rit = " << *rit << std::endl;
        --rit;
    }
    std::cout << "--------- TEST THE OPERATOR OBJECT + NUMBER ---------------" << std::endl << std::endl;

    std::cout << "      rit = " << *rit << std::endl;
    rit = rit + 8;
    std::cout << "      rit + 8 = " << *rit << std::endl;
    std::cout << "--------- TEST THE OPERATOR OBJECT - NUMBER ---------------" << std::endl << std::endl;
    std::cout << "      rit = " << *rit << std::endl;
    rit = rit - 7;
    std::cout << "      rit - 7 = " << *rit << std::endl;

    std::cout << "--------- TEST THE OPERATOR OBJECT += NUMBER ---------------" << std::endl << std::endl;

    std::cout << "      rit += 2 : " << *(rit += 2) << std::endl;
    std::cout << "--------- TEST THE OPERATOR OBJECT -= NUMBER ---------------" << std::endl << std::endl;

    std::cout << "      rit -= 2 : " << *(rit -= 2) << std::endl;

    std::cout << "--------- TEST THE OPERATOR LOGIQUE ==       ---------------" << std::endl << std::endl;

    ft::reverse_iterator<ft::random_access_iterator<int> > rit_r(it);


    ft::random_access_iterator<int> itn;
    itn = alloc.allocate(9);
    for (int i = 0; i < 9; i++)
    {
        *itn = i;
        itn++;
    }
    
    ft::reverse_iterator<ft::random_access_iterator<int> > rit_n(itn);

    if (rit_r.base() == rit.base())
        std::cout << "      YES rit_r == rit" << std::endl;
    else
        std::cout << "      NO rit_r == rit" << std::endl;
    
    if (rit_n.base() == rit.base())
        std::cout << "      YES rit_n == rit" << std::endl;
    else
        std::cout << "      NO rit_n == rit" << std::endl;

    
    std::cout << "--------- TEST THE OPERATOR LOGIQUE <        ---------------" << std::endl << std::endl;

    if (rit_r.base() < rit.base())
        std::cout << "      YES rit_r < rit" << std::endl;
    else
        std::cout << "      NO rit_r < rit" << std::endl;
    
    std::cout << "--------- TEST THE OPERATOR LOGIQUE >        ---------------" << std::endl << std::endl;

    if (rit_n.base() > rit.base())
        std::cout << "      YES rit_n > rit" << std::endl;
    else
        std::cout << "      NO rit_n > rit" << std::endl;

    std::cout << "--------- TEST THE OPERATOR LOGIQUE <=       ---------------" << std::endl << std::endl;

    if (rit_n.base() <= rit.base())
        std::cout << "      YES rit_n <= rit" << std::endl;
    else
        std::cout << "      NO rit_n <= rit" << std::endl;

    std::cout << "--------- TEST THE OPERATOR LOGIQUE >=       ---------------" << std::endl << std::endl;

    if (rit_n.base() >= rit.base())
        std::cout << "      YES rit_n >= rit" << std::endl;
    else
        std::cout << "      NO rit_n >= rit" << std::endl;

    std::cout << "--------- TEST THE OPERATOR LOGIQUE OBJECT == OBJECT -------" << std::endl << std::endl;

    if (rit_n == rit)
        std::cout << "      YES rit_n == rit" << std::endl;
    else
        std::cout << "      NO rit_n == rit" << std::endl;

    std::cout << "--------- TEST THE OPERATOR LOGIQUE OBJECT > OBJECT -------" << std::endl << std::endl;

    if (rit_n > rit)
        std::cout << "      YES rit_n > rit" << std::endl;
    else
        std::cout << "      NO rit_n > rit" << std::endl;

    std::cout << "--------- TEST THE OPERATOR LOGIQUE OBJECT != OBJECT -------" << std::endl << std::endl;

    if (rit_n != rit)
        std::cout << "      YES rit_n != rit" << std::endl;
    else
        std::cout << "      NO rit_n != rit" << std::endl;

    std::cout << "--------- TEST THE OPERATOR LOGIQUE OBJECT < OBJECT -------" << std::endl << std::endl;

    if (rit_n < rit)
        std::cout << "      YES rit_n < rit" << std::endl;
    else
        std::cout << "      NO rit_n < rit" << std::endl;

    std::cout << "--------- TEST THE OPERATOR LOGIQUE OBJECT <= OBJECT -------" << std::endl << std::endl;

    if (rit_n <= rit)
        std::cout << "      YES rit_n <= rit" << std::endl;
    else
        std::cout << "      NO rit_n <= rit" << std::endl;

    std::cout << "--------- TEST THE OPERATOR LOGIQUE OBJECT >= OBJECT -------" << std::endl << std::endl;

    if (rit_n >= rit)
        std::cout << "      YES rit_n >= rit" << std::endl;
    else
        std::cout << "      NO rit_n >= rit" << std::endl;

    std::cout << "--------- TEST THE OPERATOR OBJECT - OBJECT -------" << std::endl << std::endl;

    std::cout << "      rit - rit = " << rit - rit << std::endl;
    std::cout << "      rit - rit_n = " << rit - rit_n << std::endl;
    std::cout << "      rit_n - rit = " << rit_n - rit << std::endl;

    std::cout << "--------- TEST THE OPERATOR OBJECT - NUMBER -------" << std::endl << std::endl;

    rit = rit - 1;
    std::cout << "      rit_n - 1 = " << *rit << std::endl;



}