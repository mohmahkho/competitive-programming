template<typename T>
struct bit {
  using mask_t = typename make_unsigned<T>::type;
  constexpr static auto val(mask_t x, int j) -> int { return !!(x >> j & mask_t(1)); }
  constexpr static auto set(mask_t x, int j) -> T { return mask_t(1) << j | x; }
  constexpr static auto reset(mask_t x, int j) -> T { return ~(mask_t(1) << j) | x; }
  constexpr static auto flip(mask_t x, int j) -> T { return mask_t(1) << j ^ x; }
  /* TODO :
   * rotl
   * rotr
   * segment set
   * segment reset
   * highest power of 2
   * next submask
   * next overmask
   * basically every __builtin!!
   *
   * */
};
