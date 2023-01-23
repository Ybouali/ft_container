#pragma once

#include "../vector/vector.hpp"
#include "../map/utils/Node_avl.hpp"

namespace ft {
    
    template <class P, class T>
    class bidirectional_iterator 
    {
        private :
            typedef T*                             node_type_p;

            node_type_p get_next_min(node_type_p _node)
            {
                if (!_node)
                    return nullptr;
                while (_node && _node->left)
                    _node = _node->left;
                return _node;
            }

            node_type_p get_next_max(node_type_p _node)
            {
                while (_node && _node->right)
                    _node = _node->right;
                return _node;
            }

            node_type_p  decrement(node_type_p r_node)
            {
                node_type_p parent;
                if (r_node && r_node->left)
                    r_node = get_next_max(r_node->left);
                else if (r_node)
                {
                    parent = r_node->parent;
                    while (parent && r_node == parent->left)
                    {
                        r_node = parent;
                        parent = parent->parent;
                    }
                    r_node = parent;
                }
                return r_node;
            }

            node_type_p increment(node_type_p r_node)
            {
                if (r_node == _end)
                    return nullptr;
                node_type_p parent;

                if (r_node && r_node->right)
                    r_node = get_next_min(r_node->right);
                else if (r_node)
                {
                    parent = r_node->parent;
                    while (parent && r_node == parent->right)
                    {
                        r_node = parent;
                        parent = parent->parent;
                    }
                    r_node = parent;
                }
                return r_node;
            }
        public:
            typedef std::bidirectional_iterator_tag     iterator_category;
            typedef P                                   value_type;
            typedef ptrdiff_t                           difference_type;
            typedef size_t                              size_type;
            typedef P*                                  pointer;
            typedef P&                                  reference;

            bidirectional_iterator() : _node_curr(), _end() {}


            template <class _P, class _T>
            bidirectional_iterator(const bidirectional_iterator<_P, _T> & other) { 
                this->_node_curr = other.base();
                this->_end = other.base_e();
            }

            bidirectional_iterator& operator=(const bidirectional_iterator& other) 
            {
                 
                this->_node_curr = other._node_curr;
                this->_end = other._end;
                return *this;
            }

            bidirectional_iterator(node_type_p node, node_type_p last)
            {
                _node_curr = node;
                _end = last;
            }

            bidirectional_iterator(node_type_p node)
            {
                _node_curr = node;
                _end = nullptr;
            }

            ~bidirectional_iterator() {}
            
            reference   operator*() const {  return *(_node_curr->data); }

            pointer     operator->() const { return &(operator*()); }

            bidirectional_iterator& operator++(void)
            {
                _node_curr = increment(_node_curr);
                
                if (_node_curr == nullptr)
                {
                    _node_curr = nullptr;
                    return *this;
                }
                return (*this);
            }

            bidirectional_iterator operator++(int)
            {
                node_type_p node = _node_curr;

                _node_curr = increment(_node_curr);
                return (node);
            }

            bidirectional_iterator& operator--(void)
            {
                if (!_node_curr)
                    _node_curr = _end;
                else
                    _node_curr = decrement(_node_curr);
                return (*this);
            }

            bidirectional_iterator operator--(int)
            {
                node_type_p r_node;
                r_node = _node_curr;

                if (!_node_curr)
                {
                    _node_curr = _end;
                    r_node = _end;
                }
                else 
                    _node_curr = decrement(_node_curr);
                return (r_node);
            }

            template <class _P, class _T>
            bool operator==(const bidirectional_iterator<_P, _T>& other) const { return base() == other.base(); }

            template <class _P, class _T>
            bool operator!=(const bidirectional_iterator<_P, _T>& other) const { return base() != other.base(); };

            node_type_p     base() const { return _node_curr; };

            node_type_p     base_e() const { return _end; };
        private :
            node_type_p     _node_curr;
            node_type_p     _end;
    };
}