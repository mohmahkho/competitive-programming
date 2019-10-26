/** Assignment **/
int mask = 0b0110011; // base 2 assignment
int mask = 0xFA6; // base 16 assignment
int mask = 373492; // base 10 assignment

/** Divide by 2 (Floor) **/
mask >>= 1;

/** Divide by 2 (Ceil) **/
mask = (mask + 1) >> 1;
// or
++mask >>= 1;

/** Set the j'th bit **/
mask |= 1 << j;

/** Clear the j'th bit **/
mask &= ~(1 << j);

/** Toggle the j'th bit **/
mask ^= 1 << j;

/** Get the value of the j'th bit **/
mask & 1 << j

/** Check if the j'th bit is set **/
(mask & 1 << j) > 0

/** Get value of least significat bit that is on **/
mask & -mask

/** Set n least significant bits **/
mask = (1 << n) - 1;

/** Get all submasks of a mask **/
// Not including mask 0 as submask
for(int sub_mask = mask; sub_mask; sub_mask = (sub_mask - 1) & mask) {

}
// Including mask 0 as submask
for(int sub_mask = mask; ; sub_mask = (sub_mask - 1) & mask) {
  
    if(sub_mask == 0) break;
}
