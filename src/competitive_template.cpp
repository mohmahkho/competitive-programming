#include <bits/stdc++.h>

namespace mk{namespace ds{ // range, matrix, tensor
#ifndef _MK_DS_RANGE_
#define _MK_DS_RANGE_
template<class T,class Alloc=std::allocator<T>>class range:public std::vector<T,
Alloc>{typedef std::vector<T,Alloc> base;typedef int range_type;typedef typename
base::size_type size_type;typedef typename base::value_type value_type;typedef
value_type& reference;range_type _first;public:range():base(),_first(0){}range(
range_type first,range_type last):base(last-first),_first(first){}range(
size_type n):base(n),_first(0){}range(std::initializer_list<T> il,range_type 
first=0):base(il),_first(first){}reference operator[](range_type i){return base
::operator[](i-_first);}reference at(range_type i){return base::at(i - _first);}
void rearrange(range_type first,range_type last){this->_first=first;base::resize
(last-first);}void set_first(range_type first){this->_first=first;}range_type 
first(){return _first;}range_type last(){return _first+(range_type)base::size();
}};
#endif
#ifndef _MK_DS_MATRIX_
#define _MK_DS_MATRIX_
template<class T,class Alloc=std::allocator<T>>class matrix:public std::vector<
std::vector<T,Alloc>,Alloc>{typedef std::vector<T,Alloc> vec1d;typedef std::
vector<vec1d,Alloc> vec2d;typedef typename vec1d::size_type size_type;public:
matrix()=default;matrix(size_type rows,size_type cols):vec2d(rows,vec1d(cols)){}
matrix(size_type n):vec2d(n,vec1d(n)){}void resize(size_type rows,size_type cols
){vec2d::resize(rows);for(vec1d& row:*this){row.resize(cols);}}size_type rows(){
return (*this).size();}size_type cols(){return (*this).at(0).size();}};
#endif
#ifndef _MK_DS_TENSOR_
#define _MK_DS_TENSOR_
template<class T,class Alloc=std::allocator<T>>class tensor:public std::vector<
std::vector<std::vector<T,Alloc>,Alloc>,Alloc>{typedef std::vector<T,Alloc> 
vec1d;typedef std::vector<vec1d,Alloc> vec2d;typedef std::vector<vec2d,Alloc>
vec3d;typedef typename vec1d::size_type size_type;public:tensor()=default;tensor
(size_type layers,size_type rows,size_type cols):vec3d(layers,vec2d(rows,vec1d(
cols))){}tensor(size_type n):vec3d(n,vec2d(n,vec1d(n))){}void resize(size_type 
layers,size_type rows,size_type cols){vec3d::resize(layers);for(vec2d& layer:*
this){layer.resize(rows);for(vec1d& row:layer){row.resize(cols);}}}size_type 
layers(){return (*this).size();}size_type rows(){return (*this).at(0).size();}
size_type cols(){return (*this).at(0).at(0).size();}};
#endif
} }


#define rep(i, a, comp, b) for(auto i = a; i comp b; ++i)
#define per(i, a, comp, b) for(auto i = a; i comp b; --i)
#define loop(i, a, comp, b, op) for(auto i = a; i comp b; i op)
#define sz(x) ((int)sizeof(x))
#define MAXIN 100010
#define MOD 1000000007
#define INF 2000000000
#define pb push_back
#define eb emplace_back
using ll  = long long;
using ull = unsigned long long;
using ii  = std::pair<int, int>;
using namespace std;

int main()
{
}
