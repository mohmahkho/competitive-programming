/*
The idea behind lazy segment tree is that if you are on a node of segment and has lazy this node is affected by lazy but not
it's children. when even (in update / query) you are going down because the segment tree l and r are not completely inside ql and qr
you should push lazy down if there is a lazy. so lazy push down happens in both update and query.
*/
