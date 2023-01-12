namespace ft
{
    template <class T1, class T2>
    class pair
    {
        public :
            typedef T1 first_type;
            typedef T2 second_type;
            
            first_type      first;
            second_type     second;

            pair(): first(), second() {}
            
            pair(const first_type& f_p, const second_type& s_p) : first(f_p), second(s_p) { }

            template <class T8, class T9>
            pair(const pair<T8, T9>& other): first(other.first), second(other.second) {}

            pair& operator=(const pair& other) { 
                first = other.first;
                second = other.second;
                return *this;
            }

            template <class T3, class T4>
            friend bool operator== (const pair<T3,T4>& lhs, const pair<T3,T4>& rhs);

            template <class T3, class T4>
            friend bool operator!= (const pair<T3,T4>& lhs, const pair<T3,T4>& rhs);

            template <class T3, class T4>
            friend bool operator<  (const pair<T3,T4>& lhs, const pair<T3,T4>& rhs);

            template <class T3, class T4>
            friend bool operator<= (const pair<T3,T4>& lhs, const pair<T3,T4>& rhs);

            template <class T3, class T4>
            friend bool operator>  (const pair<T3,T4>& lhs, const pair<T3,T4>& rhs);

            template <class T3, class T4>
            friend bool operator>= (const pair<T3,T4>& lhs, const pair<T3,T4>& rhs);
    };

    template <class T3, class T4>
    bool operator== (const pair<T3,T4>& lhs, const pair<T3,T4>& rhs) { return lhs.first==rhs.first && lhs.second==rhs.second; }

    template <class T3, class T4>
    bool operator!= (const pair<T3,T4>& lhs, const pair<T3,T4>& rhs) { return !(lhs==rhs); }

    template <class T3, class T4>
    bool operator<  (const pair<T3,T4>& lhs, const pair<T3,T4>& rhs) { return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second); }

    template <class T3, class T4>
    bool operator<= (const pair<T3,T4>& lhs, const pair<T3,T4>& rhs) { return !(rhs<lhs); }

    template <class T3, class T4>
    bool operator>  (const pair<T3,T4>& lhs, const pair<T3,T4>& rhs) { return rhs<lhs; }

    template <class T3, class T4>
    bool operator>= (const pair<T3,T4>& lhs, const pair<T3,T4>& rhs) { return !(lhs<rhs); }

    template <class T3, class T4>
    ft::pair<T3, T4> make_pair(T3 X, T4 Y ) { return pair<T3, T4>(X, Y); }
}