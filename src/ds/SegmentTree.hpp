#include <vector>

template<class T, class BinaryOperation, T identity_element>
class SegmentTree
{
public:
    using size_type = std::size_t;
    using value_type = T;

private:
    size_type n;
    BinaryOperation op;
    std::vector<value_type> segment_tree;
    std::vector<value_type> A;

    inline size_type left(size_type p) {
        return (p << 1) + 1;
    }

    inline size_type right(size_type p) {
        return (p << 1) + 2;
    }

    void build(size_type node_idx, size_type left_idx, size_type right_idx) {
        if(left_idx == right_idx) {
            segment_tree[node_idx] = A[left_idx];
            return ;
        }

        build(left(node_idx), left_idx, (left_idx + right_idx) / 2);
        build(right(node_idx), (left_idx + right_idx) / 2 + 1, right_idx);
        
        segment_tree[node_idx] = op(segment_tree[left(node_idx)],
                                    segment_tree[right(node_idx)]);
    }

    value_type rq(size_type node_idx, size_type left_idx, size_type right_idx,
                  size_type L, size_type R)
    {
        if(right_idx < L or left_idx > R) {
            return identity_element;
        }

        if(left_idx >= L and right_idx <= R) {
            return segment_tree[node_idx];
        }
        return op(rq(left(node_idx), left_idx, (left_idx + right_idx) / 2,
                     L, R), 
                  rq(right(node_idx), (left_idx + right_idx) / 2 + 1, right_idx,
                     L, R));
    }

    void update(size_type node_idx, size_type left_idx, size_type right_idx, 
                size_type update_idx, size_type update_value) {
        if(left_idx == right_idx and left_idx == update_idx) {
            segment_tree[node_idx] = update_value;
            return ;
        }
        if(update_idx <= (left_idx + right_idx) / 2) {
            update(left(node_idx), left_idx, (left_idx + right_idx) / 2,
                   update_idx, update_value);
        } else {
            update(right(node_idx), (left_idx + right_idx) / 2 + 1, right_idx,
                   update_idx, update_value);
        }
        segment_tree[node_idx] = op(segment_tree[left(node_idx)],
                                    segment_tree[right(node_idx)]);
    }

public:
    SegmentTree(const std::vector<value_type>& A)
    : A(A), n(A.size()), op(BinaryOperation()) {
        segment_tree.assign(4 * n, identity_element);
        build(0, 0, n - 1);
    }

    value_type rq(size_type L, size_type R) {
        return rq(0, 0, n - 1, L, R);
    }

    void update(size_type update_idx, value_type update_value) {
        if(update_idx >= n or update_idx < 0) return; // invalid update
        update(0, 0, n - 1, update_idx, update_value);
    }

};
