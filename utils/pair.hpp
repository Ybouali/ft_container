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
            
            pair(const first_type& f_p, const second_type& s_p): first(f_p), second(s_p) {}

            pair(const pair& other): first(other.first), second(other.second) {}        
    };

    template <class T1, class T2>
    pair<T1, T2> make_pair(T1 X, T2 Y ) { return pair<T1, T2>(X, Y); }
}